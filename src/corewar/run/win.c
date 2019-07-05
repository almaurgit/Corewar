/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 01:26:32 by efouille          #+#    #+#             */
/*   Updated: 2019/06/04 22:17:58 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "ft_printf.h"
#include "libft_const.h"
#include "lftstring.h"
#include <ncurses.h>

void		announce_winner(t_corewar *c)
{
	char	*name;
	int		i;
	int		win_i;
	int		max_last_live;

	i = 0;
	win_i = 0;
	max_last_live = 0;
	while (i < c->nplayers)
	{
		if (c->players[i]->last_live > max_last_live)
		{
			win_i = i;
			max_last_live = c->players[i]->last_live;
		}
		++i;
	}
	name = c->players[win_i]->name;
	ft_printf("Contestant %d, ", c->players[win_i]->number);
	ft_printf("\"%s\", has won !\n", name);
}

static void	tui_print_winner(t_corewar *c, char *name, int win_i)
{
	int	len_name;
	int	len_spaces;
	int	number_winner;
	int	n;

	len_name = ft_strlen(name);
	len_spaces = (71 - len_name) / 2;
	number_winner = c->players[win_i]->number;
	mvvline(30, 61, (int)' ' | COLOR_PAIR(100), 8);
	mvvline(30, 133, (int)' ' | COLOR_PAIR(100), 8);
	mvhline(30, 61, (int)' ' | COLOR_PAIR(100), 73);
	mvhline(37, 61, (int)' ' | COLOR_PAIR(100), 73);
	mvhline(31, 62, ' ', 71);
	attron(A_BOLD);
	mvprintw(32, 62, "%31sPlayer %d%n", "", number_winner, &n);
	printw("%*s", 71 - n, "");
	attron(COLOR_PAIR(win_i % 4 + 1));
	mvprintw(33, 62, "%*s%s", len_spaces, "", name);
	printw("%*s", len_name % 2 ? len_spaces : len_spaces + 1, "");
	attroff(COLOR_PAIR(win_i % 4 + 1));
	mvhline(34, 62, ' ', 71);
	mvprintw(35, 62, "%31sHAS WON !%31s", "", "");
	mvhline(36, 62, ' ', 71);
	attroff(A_BOLD);
}

void		tui_announce_winner(t_corewar *c)
{
	char	*name;
	int		i;
	int		win_i;
	int		max_last_live;

	i = 0;
	win_i = 0;
	max_last_live = 0;
	while (i < c->nplayers)
	{
		if (c->players[i]->last_live > max_last_live)
		{
			win_i = i;
			max_last_live = c->players[i]->last_live;
		}
		++i;
	}
	name = c->players[win_i]->name;
	tui_print_winner(c, name, win_i);
}
