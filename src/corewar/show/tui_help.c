/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tui_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:16:01 by amaurel           #+#    #+#             */
/*   Updated: 2019/05/22 19:43:05 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_types.h"
#include <ncurses.h>

static void	delete_help(t_corewar *c)
{
	int	x;
	int	y;

	x = c->nplayers > 4 ? 253 : 199;
	y = c->nplayers > 4 ? -1 : 31;
	while (++y < 63)
		mvprintw(y, x, "%47s", "");
}

static void	print_signature(int x, int y)
{
	attron(COLOR_PAIR(3));
	mvprintw(y + 23, x + 2, " _______  _______ _    _____ _____");
	mvprintw(y + 24, x + 2, "/ __/ _ \\/ __/ -_) |/|/ / _ `/ __/");
	mvprintw(y + 25, x + 2, "\\__/\\___/_/  \\__/|__,__/\\_,_/_/  ");
	attroff(COLOR_PAIR(3));
	mvprintw(y + 27, x, "amaurel - efouille - lduqueno - rlegan");
}

static void	print_help(t_corewar *c)
{
	int	y;
	int	x;

	x = c->nplayers > 4 ? 257 : 203;
	y = c->nplayers > 4 ? 2 : 34;
	attron(A_BOLD);
	mvprintw(y, x, "Press 'p' to print properties of");
	mvprintw(y + 1, x, "each process");
	mvprintw(y + 3, x, "Press 'o' and 'l' scroll through");
	mvprintw(y + 4, x, "the processes (if 'p' activated)");
	mvprintw(y + 6, x, "Press 's' to cancel the display of");
	mvprintw(y + 7, x, "processes");
	mvprintw(y + 9, x, "Press the arrow keys to modify the");
	mvprintw(y + 10, x, "number of cycles per second (press");
	mvprintw(y + 11, x, "'m' for max speed)");
	mvprintw(y + 13, x, "Press the space bar to start the");
	mvprintw(y + 14, x, "program, or to pause it");
	mvprintw(y + 16, x, "Press 'n' to run only one cycle");
	mvprintw(y + 18, x, "Press 'c' to change the colors of the");
	mvprintw(y + 19, x, "champions");
	mvprintw(y + 21, x, "Press 'q' to quit the program");
	attroff(A_BOLD);
	print_signature(x, y);
}

void		ft_help(t_corewar *c)
{
	int x;
	int y;

	x = c->nplayers > 4 ? 253 : 199;
	y = c->nplayers > 4 ? 0 : 32;
	if (!(c->tui_help))
	{
		mvvline(y, x, (int)' ' | COLOR_PAIR(100), 30);
		mvvline(y, x + 46, (int)' ' | COLOR_PAIR(100), 30);
		mvhline(y, x, (int)' ' | COLOR_PAIR(100), 47);
		mvhline(y + 30, x, (int)' ' | COLOR_PAIR(100), 47);
		print_help(c);
	}
	else
		delete_help(c);
	c->tui_help = !c->tui_help;
}
