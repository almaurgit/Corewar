/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tui_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 19:25:48 by amaurel           #+#    #+#             */
/*   Updated: 2019/06/04 22:42:12 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "lftmath.h"
#include "lftstring.h"
#include <unistd.h>
#include <ncurses.h>

static int		nprocs_player(t_corewar *c, int player)
{
	int	i;
	int	nprocs;

	nprocs = 0;
	i = 0;
	while (i < c->nprocs)
	{
		if (c->procs[i] && c->procs[i]->player == player)
			++nprocs;
		++i;
	}
	return (nprocs);
}

static void		tui_info_players(t_corewar *c)
{
	int		i;
	t_i32	y;
	int		len_name;

	i = 0;
	y = 10;
	while (i < c->nplayers && i < 12)
	{
		mvprintw(y, 200, "Player %d : ", c->players[i]->number);
		attron(COLOR_PAIR(i % 4 + 1));
		len_name = ft_strlen(c->players[i]->name);
		if (len_name < 39)
			printw("%s", c->players[i]->name);
		else
			printw("%.35s...", c->players[i]->name);
		attroff(COLOR_PAIR(i % 4 + 1));
		mvprintw(y + 1, 202, "Last live : %d", c->players[i]->last_live);
		move(y + 2, 202);
		printw("Number of active processes : %d      ", nprocs_player(c, i));
		y += 4;
		i++;
	}
}

static void		tui_info_aff(t_corewar *c)
{
	int	y;
	int	x;

	y = 2;
	x = ft_sqrt(MEM_SIZE) * 3 + 5;
	attron(A_BOLD);
	mvprintw(y, x + 18, !c->tui_pause ? "*** RUNNING ***" : "*** PAUSED *** ");
	mvprintw(y + 2, x, "Cycle : %d ", c->cycles);
	if (c->cycles_per_s < 1000)
		printw("(max per second : %d)   ", c->cycles_per_s);
	else
		printw("(max per second : max)   ", c->cycles_per_s);
	move(y + 4, x);
	printw("Cycles before next cleaning : %d   ", c->next_kill - c->cycles);
	mvprintw(y + 6, x, "Processes : %d", c->nprocs);
	tui_info_players(c);
	y = y + 8 + (c->nplayers <= 12 ? c->nplayers : 12) * 4;
	mvprintw(y, x, "CYCLE_TO_DIE : %d   ", c->cycles_to_die);
	mvprintw(y + 2, x, "CYCLE_DELTA : %d   ", CYCLE_DELTA);
	mvprintw(y + 4, x, "Total lives : %d   ", c->total_live);
	attroff(A_BOLD);
	mvprintw(64, 231, "Press 'h' for help");
}

int				tui_info(t_corewar *c, t_u8 end)
{
	int		i;
	t_i8	ch;

	i = 0;
	tui_info_aff(c);
	ch = getch();
	if (ch == 'q')
		return (0);
	else if (ch == ' ' && !end)
		c->tui_pause = !c->tui_pause;
	else if (ch == 'l' && c->tui_proc0 >= 0)
		c->tui_proc0 += (int)c->tui_proc0 < c->nprocs - 1 ? 1 : 0;
	else if (ch == 'o' && c->tui_proc0 >= 0)
		c->tui_proc0 -= (int)c->tui_proc0 > 0 ? 1 : 0;
	else if (ch == 'c')
		change_colors();
	else
	{
		while (ch != f_getch()[i].ch && f_getch()[i].ch != 0)
			i++;
		if (f_getch()[i].ch)
			f_getch()[i].f_ch(c);
	}
	return (1);
}
