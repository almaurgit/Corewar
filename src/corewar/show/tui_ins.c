/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tui_ins.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:16:01 by amaurel           #+#    #+#             */
/*   Updated: 2019/05/22 19:40:47 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	tui_print_arg(t_args *a, t_op *op, int arg)
{
	printw("|");
	if (a->argt[arg] == REG_CODE)
		printw("r%-11d", a->args[arg]);
	else if (a->argt[arg] == DIR_CODE && !op->is_index)
		printw("%%%-11d", a->args[arg]);
	else if (a->argt[arg] == DIR_CODE && op->is_index)
		printw("%%%-11hd", a->args[arg]);
	else
		printw("%-12d", a->args[arg]);
}

static void	tui_print_ins(t_corewar *c, int i, int owner)
{
	t_args	*a;
	t_op	*op;
	int		arg;

	a = c->procs[i + c->tui_proc0]->exec->a;
	op = &ops()[c->procs[i + c->tui_proc0]->exec->opcode - 1];
	arg = 0;
	attron(A_UNDERLINE | COLOR_PAIR(owner));
	mvprintw(67 + i, 195, "%7s%4s|", op->name, "");
	printw("%-4d", c->procs[i + c->tui_proc0]->exec->remaining_cycles);
	while (arg < a->argc)
	{
		tui_print_arg(a, op, arg);
		arg++;
	}
	while (arg < 3)
	{
		printw("|%12s", "");
		arg++;
	}
	attroff(A_UNDERLINE | COLOR_PAIR(owner));
}

void		tui_ins(t_corewar *c, int i, int owner)
{
	if (c->procs[i + c->tui_proc0]->exec)
		tui_print_ins(c, i, owner);
	else if (c->procs[c->tui_proc0 + i])
	{
		attron(A_UNDERLINE | COLOR_PAIR(owner));
		mvprintw(67 + i, 195, "%11s|%4s|%12s|%12s|%12s", "", "", "", "", "");
		attroff(A_UNDERLINE | COLOR_PAIR(owner));
	}
}
