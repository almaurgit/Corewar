/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 12:13:40 by efouille          #+#    #+#             */
/*   Updated: 2019/05/14 19:03:00 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_types.h"
#include <stdlib.h>

static void	clean_exec(t_corewar *c, int i)
{
	if (c->procs[i]->exec)
	{
		free(c->procs[i]->exec->a->args);
		free(c->procs[i]->exec->a->argt);
		free(c->procs[i]->exec->a);
		free(c->procs[i]->exec);
	}
}

void		clean_proc(t_corewar *c, int i)
{
	if (c->procs[i])
	{
		free(c->procs[i]->reg);
		clean_exec(c, i);
		free(c->procs[i]);
		c->procs[i] = NULL;
	}
}

void		clean_procs(t_corewar *c)
{
	int	i;

	i = 0;
	while (i < c->nprocs)
	{
		clean_proc(c, i);
		++i;
	}
	free(c->procs);
	c->procs = NULL;
}
