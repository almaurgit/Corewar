/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:35:11 by efouille          #+#    #+#             */
/*   Updated: 2019/05/22 19:54:23 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "lftlib.h"
#include "lftmath.h"
#include <stdlib.h>

static t_u8	get_ocp(t_corewar *c, int i, t_u8 op)
{
	t_u8	ocp;

	if (op == 0x01)
		ocp = 0x80;
	else if (op == 0x09)
		ocp = 0x80;
	else if (op == 0x0c)
		ocp = 0x80;
	else if (op == 0x0f)
		ocp = 0x80;
	else
		read_mem(c, c->procs[i]->pc + c->procs[i]->delta_pc, &ocp, 1);
	return (ocp);
}

static void	treat_args(t_corewar *c, int p, t_args *a, t_u8 dir_size)
{
	int	*pc;
	int	*dpc;
	int	i;
	int	size;

	pc = &(c->procs[p]->pc);
	dpc = &(c->procs[p]->delta_pc);
	i = 0;
	while (i < a->argc)
	{
		size = a->argt[i] == DIR_CODE ? dir_size : IND_SIZE;
		if (a->argt[i] == REG_CODE)
		{
			read_mem(c, c->procs[p]->pc + *dpc, (t_u8*)&(a->args[i]), 1);
			size = 1;
		}
		else if (a->argt[i] == DIR_CODE)
			read_mem(c, *pc + *dpc, (t_u8*)&(a->args[i]), size);
		else if (a->argt[i] == IND_CODE)
			read_mem(c, *pc + *dpc, (t_u8*)&(a->args[i]), size);
		if (a->argt[i] == DIR_CODE || a->argt[i] == IND_CODE)
			ft_swapbytes((t_u8*)&(a->args[i]), size);
		c->procs[p]->delta_pc += size;
		++i;
	}
}

static void	get_args(t_corewar *c, int p, t_u8 op, t_args *a)
{
	t_u8	ocp;
	int		i;
	t_u8	dir_size;

	ocp = get_ocp(c, p, op);
	if (ops()[op - 1].has_ocp)
		c->procs[p]->delta_pc += 1;
	dir_size = ops()[op - 1].is_index ? IND_SIZE : DIR_SIZE;
	i = 0;
	while (i < a->argc)
	{
		a->argt[i] = (ocp >> (3 * 2 - i * 2)) & 3;
		++i;
	}
	treat_args(c, p, a, dir_size);
}

int			treat_instruction(t_corewar *c, int i)
{
	int		*pc;
	t_u8	op;
	t_args	*a;
	t_exec	*exec;

	pc = &(c->procs[i]->pc);
	op = c->mem[*pc];
	if (!(a = (t_args*)ft_memalloc(sizeof(t_args))))
		return (cw_malloc_error);
	c->procs[i]->delta_pc = 1;
	a->argc = ops()[op - 1].argc;
	a->args = (int*)ft_memalloc(a->argc * sizeof(int));
	a->argt = (t_u8*)ft_memalloc(a->argc * sizeof(t_u8));
	if (!(a->args) || !(a->argt))
		return (cw_malloc_error);
	get_args(c, i, op, a);
	if (!(exec = (t_exec*)malloc(sizeof(t_exec))))
		return (cw_malloc_error);
	exec->remaining_cycles = ops()[op - 1].n_cycles;
	exec->opcode = op;
	exec->a = a;
	exec->done = 0;
	c->procs[i]->exec = exec;
	c->procs[i]->waiting = 1;
	return (0);
}
