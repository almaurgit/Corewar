/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:03:10 by efouille          #+#    #+#             */
/*   Updated: 2019/05/28 05:51:23 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "lftmath.h"
#include "lftstring.h"
#include "ft_printf.h"

static void	treat_proc(t_corewar *c, int i)
{
	int		*pc;
	t_u8	op;

	pc = &(c->procs[i]->pc);
	read_mem(c, *pc, &(op), 1);
	if (op > 0 && op <= 16)
		treat_instruction(c, i);
	else
		increase_pc(pc, 1);
}

int			interrupt_loop(t_corewar *c)
{
	if (c->cycles == c->dump)
	{
		if (c->tui)
			c->tui_pause = 1;
		else if (c->dump > 0)
		{
			dump(c, c->dump_size > 0 ? c->dump_size : 32);
			return (1);
		}
	}
	return (0);
}

void		run_step(t_corewar *c)
{
	int	i;

	i = c->nprocs - 1;
	while (i >= 0)
	{
		if (c->procs[i])
		{
			c->pc[c->procs[i]->pc] = c->procs[i]->player;
			if (!c->procs[i]->waiting)
			{
				c->procs[i]->execed_this_cycle = 0;
				treat_proc(c, i);
			}
		}
		--i;
	}
	i = c->nprocs;
	while (--i >= 0)
		if (c->procs[i]
			&& c->procs[i]->exec && !(c->procs[i]->exec->done))
			execute(c, i);
	if (c->cycles >= c->next_kill)
		kill(c);
}

void		corewar_loop(t_corewar *c)
{
	int	ret;

	ret = 1;
	while (c->nliving || (c->tui && c->tui_pause))
	{
		if (c->verbose & V_CYCLES)
		{
			ft_printf("It is now cycle %d ", c->cycles);
			ft_printf("{cycle to die %d}\n", c->cycles_to_die);
		}
		if (!c->tui_pause)
		{
			run_step(c);
			if (interrupt_loop(c))
				break ;
			++(c->cycles);
		}
		if (c->tui && !(ret = tui(c, 0)))
			break ;
		if (!c->tui_pause)
			ft_memset(c->pc, -1, MEM_SIZE);
	}
	if (c->tui && ret)
		tui(c, 1);
	announce_winner(c);
}
