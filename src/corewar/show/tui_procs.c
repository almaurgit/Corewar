/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tui_procs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:16:01 by amaurel           #+#    #+#             */
/*   Updated: 2019/05/22 19:40:00 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	print_procs(t_corewar *c, int *i, int j, int owner)
{
	if (c->procs[*i + c->tui_proc0])
	{
		j = 0;
		owner = (c->procs[*i + c->tui_proc0]->player % 4 + 1) * 10 + 5;
		attron(A_UNDERLINE | COLOR_PAIR(owner));
		mvprintw(67 + *i, 1, "%-7d|", *i + c->tui_proc0);
		printw("%-7d|", c->procs[*i + c->tui_proc0]->pc);
		printw("%-1d", c->procs[*i + c->tui_proc0]->carry);
		while (j < REG_NUMBER)
		{
			printw("| %08x ", c->procs[*i + c->tui_proc0]->reg[j]);
			++j;
		}
		attroff(A_UNDERLINE | COLOR_PAIR(owner));
		tui_ins(c, *i, owner);
		++(*i);
	}
	else
	{
		mvprintw(67 + *i, 1, "%-7d%91sDEAD%91s", c->tui_proc0 + *i, "", "");
		mvprintw(67 + *i, 195, "%55s", "");
		++(*i);
	}
}

static void	tab_procs(t_corewar *c)
{
	int	i;
	int	j;
	int	owner;

	i = 0;
	j = 0;
	owner = 0;
	mvhline(74, 0, (int)' ' | COLOR_PAIR(100), 194);
	mvvline(66, 0, (int)' ' | COLOR_PAIR(100), 9);
	mvvline(66, 194, (int)' ' | COLOR_PAIR(100), 9);
	mvhline(74, 195, (int)' ' | COLOR_PAIR(100), 55);
	mvvline(66, 250, (int)' ' | COLOR_PAIR(100), 9);
	while (i < 7 && i + c->tui_proc0 < c->nprocs)
		print_procs(c, &i, j, owner);
	while (i < 7)
	{
		mvprintw(67 + i, 1, "%193s", "");
		mvprintw(67 + i++, 195, "%55s", "");
	}
}

void		ft_procs(t_corewar *c)
{
	c->tui_proc0 = c->tui_proc0 >= 0 ? c->tui_proc0 : 0;
	attron(A_UNDERLINE | COLOR_PAIR(200));
	mvprintw(66, 1, "%-7s|%-7s|%-1s|%-10s|", "Process", "Pos", "C", "  REG 1");
	printw("%-10s|%-10s|%-10s|", "  REG 2", "  REG 3", "  REG 4");
	printw("%-10s|%-10s|%-10s|", "  REG 5", "  REG 6", "  REG 7");
	printw("%-10s|%-10s|%-10s|", "  REG 8", "  REG 9", "  REG 10");
	printw("%-10s|%-10s|%-10s|", "  REG 11", "  REG 12", "  REG 13");
	printw("%-10s|%-10s|%-10s", "  REG 14", "  REG 15", "  REG 16");
	mvprintw(66, 195, "%s|%s|", "Instruction", "Cyc.");
	printw("%12s|%12s|%12s", "Arg 1    ", "Arg 2    ", "Arg 3    ");
	attroff(A_UNDERLINE | COLOR_PAIR(200));
	tab_procs(c);
}

void		ft_cancel_procs(t_corewar *c)
{
	int	i;

	i = 65;
	c->tui_proc0 = -1;
	while (++i < 75)
		mvhline(i, 0, ' ', 256);
}
