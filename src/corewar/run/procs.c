/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 10:47:24 by efouille          #+#    #+#             */
/*   Updated: 2019/05/27 18:58:53 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_types.h"
#include "lftlib.h"
#include "lftstring.h"
#include <stdlib.h>

int			fork_proc(t_corewar *c, int p, int pc)
{
	int			i;
	t_process	**procs;
	size_t		reg_sizeof;
	size_t		size;

	size = (c->nprocs + 1) * sizeof(t_process*);
	if (!(procs = (t_process**)realloc(c->procs, size)))
		return (cw_malloc_error);
	c->procs = procs;
	if (!(c->procs[c->nprocs] = (t_process*)ft_memalloc(sizeof(t_process))))
		return (cw_malloc_error);
	c->procs[c->nprocs]->player = c->procs[p]->player;
	reg_sizeof = REG_NUMBER * sizeof(int);
	if (!(c->procs[c->nprocs]->reg = (int*)malloc(reg_sizeof)))
		return (cw_malloc_error);
	i = -1;
	while (++i < REG_NUMBER)
		c->procs[c->nprocs]->reg[i] = c->procs[p]->reg[i];
	c->procs[c->nprocs]->pc = pc;
	c->procs[c->nprocs]->carry = c->procs[p]->carry;
	c->procs[c->nprocs]->waiting = 0;
	c->procs[c->nprocs]->living = c->procs[p]->living;
	++(c->nprocs);
	++(c->nliving);
	return (0);
}

static int	champs_overlap(t_corewar *c)
{
	int	max;
	int	i;
	int	size;

	i = (int)c->nplayers - 1;
	max = 1;
	while (i >= 0)
	{
		size = c->players[i]->file->header.prog_size;
		if (size > max)
			max = size;
		--i;
	}
	if (MEM_SIZE / c->nplayers <= max)
		return (1);
	return (0);
}

static int	create_proc(t_corewar *c, int i)
{
	int		j;
	int		size;
	size_t	reg_sizeof;

	if (!(c->procs[i] = (t_process*)ft_memalloc(sizeof(t_process))))
		return (cw_malloc_error);
	c->procs[i]->player = i;
	reg_sizeof = REG_NUMBER * sizeof(int);
	if (!(c->procs[i]->reg = (int*)malloc(reg_sizeof)))
		return (cw_malloc_error);
	c->procs[i]->reg[0] = c->players[i]->number;
	j = 1;
	while (j < REG_NUMBER)
	{
		c->procs[i]->reg[j] = 0;
		++j;
	}
	c->procs[i]->pc = i * MEM_SIZE / c->nplayers;
	c->procs[i]->living = 0;
	size = c->players[i]->file->header.prog_size;
	ft_memcpy(c->mem + c->procs[i]->pc, c->players[i]->file->program, size);
	ft_memset(c->owner + c->procs[i]->pc, i, size);
	return (0);
}

int			create_first_procs(t_corewar *c)
{
	int		i;

	if (!(c->procs = (t_process**)malloc(c->nplayers * sizeof(t_process*))))
		return (cw_malloc_error);
	i = (int)c->nplayers - 1;
	if (champs_overlap(c))
		return (cw_overlap_champs);
	while (i >= 0)
	{
		if (create_proc(c, i))
			return (cw_malloc_error);
		c->pc[c->procs[i]->pc] = c->procs[i]->player;
		++(c->nprocs);
		++(c->nliving);
		--i;
	}
	return (0);
}
