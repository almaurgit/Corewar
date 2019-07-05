/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:53:55 by efouille          #+#    #+#             */
/*   Updated: 2019/05/21 17:45:02 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdlib.h>

static void	free_exec(t_exec **exec)
{
	free((*exec)->a->args);
	free((*exec)->a->argt);
	free((*exec)->a);
	free((*exec));
	*exec = NULL;
}

void		execute(t_corewar *c, int i)
{
	int			dpc;
	t_ins		ins;
	t_process	*p;

	p = c->procs[i];
	if (p->exec && --(p->exec->remaining_cycles) == 0 && !p->exec->done)
	{
		if ((ins = ops()[p->exec->opcode - 1].ins))
			ins(c, i);
		p->exec->done = 1;
		p->waiting = 0;
		dpc = p->delta_pc;
		if (p->exec->opcode != 0x09 || (p->exec->opcode == 0x09 && !p->carry))
			increase_pc(&(p->pc), dpc);
		free_exec(&(p->exec));
	}
	else if (p->exec && c->mem[p->pc] != p->exec->opcode)
	{
		p->exec->remaining_cycles = 0;
		p->exec->done = 1;
		dpc = p->delta_pc;
		increase_pc(&(p->pc), dpc);
	}
}
