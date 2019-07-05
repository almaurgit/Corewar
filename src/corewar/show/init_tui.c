/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:16:01 by amaurel           #+#    #+#             */
/*   Updated: 2019/05/22 19:45:33 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_types.h"
#include "lftmath.h"
#include <ncurses.h>

static void	change_colors_bis(int i)
{
	int	nb;

	init_pair(10 + (20 + (10 * i)) % 40, COLOR_WHITE, COLOR_RED);
	init_pair(11 + (20 + i * 10) % 40 + (0 + i) % 4, COLOR_GREEN, COLOR_RED);
	init_pair(11 + (20 + i * 10) % 40 + (1 + i) % 4, COLOR_BLUE, COLOR_RED);
	init_pair(11 + (20 + i * 10) % 40 + (2 + i) % 4, COLOR_RED, COLOR_RED);
	init_pair(11 + (20 + i * 10) % 40 + (3 + i) % 4, COLOR_MAGENTA, COLOR_RED);
	init_pair(10 + (25 + (10 * i)) % 40, COLOR_BLACK, COLOR_RED);
	init_pair(10 + (30 + (10 * i)) % 40, COLOR_WHITE, COLOR_MAGENTA);
	nb = 11 + (30 + i * 10) % 40 + (0 + i) % 4;
	init_pair(nb, COLOR_GREEN, COLOR_MAGENTA);
	init_pair(11 + (30 + i * 10) % 40 + (1 + i) % 4, COLOR_BLUE, COLOR_MAGENTA);
	init_pair(11 + (30 + i * 10) % 40 + (2 + i) % 4, COLOR_RED, COLOR_MAGENTA);
	nb = 11 + (30 + i * 10) % 40 + (3 + i) % 4;
	init_pair(nb, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(10 + (35 + (10 * i)) % 40, COLOR_BLACK, COLOR_MAGENTA);
}

void		change_colors(void)
{
	static int	i = 0;

	++i;
	init_pair((0 + (10 * i)) % 40, COLOR_WHITE, COLOR_BLACK);
	init_pair(1 + (0 + i) % 4, COLOR_GREEN, COLOR_BLACK);
	init_pair(1 + (1 + i) % 4, COLOR_BLUE, COLOR_BLACK);
	init_pair(1 + (2 + i) % 4, COLOR_RED, COLOR_BLACK);
	init_pair(1 + (3 + i) % 4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair((5 + (10 * i)) % 40, COLOR_BLACK, COLOR_BLACK);
	init_pair(10 + (0 + (10 * i)) % 40, COLOR_WHITE, COLOR_GREEN);
	init_pair(11 + (0 + i * 10) % 40 + (0 + i) % 4, COLOR_GREEN, COLOR_GREEN);
	init_pair(11 + (0 + i * 10) % 40 + (1 + i) % 4, COLOR_BLUE, COLOR_GREEN);
	init_pair(11 + (0 + i * 10) % 40 + (2 + i) % 4, COLOR_RED, COLOR_GREEN);
	init_pair(11 + (0 + i * 10) % 40 + (3 + i) % 4, COLOR_MAGENTA, COLOR_GREEN);
	init_pair(10 + (5 + (10 * i)) % 40, COLOR_BLACK, COLOR_GREEN);
	init_pair(10 + (10 + (10 * i)) % 40, COLOR_WHITE, COLOR_BLUE);
	init_pair(11 + (10 + i * 10) % 40 + (0 + i) % 4, COLOR_GREEN, COLOR_BLUE);
	init_pair(11 + (10 + i * 10) % 40 + (1 + i) % 4, COLOR_BLUE, COLOR_BLUE);
	init_pair(11 + (10 + i * 10) % 40 + (2 + i) % 4, COLOR_RED, COLOR_BLUE);
	init_pair(11 + (10 + i * 10) % 40 + (3 + i) % 4, COLOR_MAGENTA, COLOR_BLUE);
	init_pair(10 + (15 + (10 * i)) % 40, COLOR_WHITE, COLOR_BLUE);
	change_colors_bis(i);
}

static void	init_pairs_bis(void)
{
	init_pair(30, COLOR_WHITE, COLOR_RED);
	init_pair(31, COLOR_GREEN, COLOR_RED);
	init_pair(32, COLOR_BLUE, COLOR_RED);
	init_pair(33, COLOR_RED, COLOR_RED);
	init_pair(34, COLOR_MAGENTA, COLOR_RED);
	init_pair(35, COLOR_BLACK, COLOR_RED);
	init_pair(40, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(41, COLOR_GREEN, COLOR_MAGENTA);
	init_pair(42, COLOR_BLUE, COLOR_MAGENTA);
	init_pair(43, COLOR_RED, COLOR_MAGENTA);
	init_pair(44, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(45, COLOR_BLACK, COLOR_MAGENTA);
	init_color(150, 500, 500, 650);
	init_pair(100, 150, 150);
	init_pair(200, COLOR_BLACK, COLOR_WHITE);
}

static void	init_pairs(void)
{
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_BLACK);
	init_pair(10, COLOR_WHITE, COLOR_GREEN);
	init_pair(11, COLOR_GREEN, COLOR_GREEN);
	init_pair(12, COLOR_BLUE, COLOR_GREEN);
	init_pair(13, COLOR_RED, COLOR_GREEN);
	init_pair(14, COLOR_MAGENTA, COLOR_GREEN);
	init_pair(15, COLOR_BLACK, COLOR_GREEN);
	init_pair(20, COLOR_WHITE, COLOR_BLUE);
	init_pair(21, COLOR_GREEN, COLOR_BLUE);
	init_pair(22, COLOR_BLUE, COLOR_BLUE);
	init_pair(23, COLOR_RED, COLOR_BLUE);
	init_pair(24, COLOR_MAGENTA, COLOR_BLUE);
	init_pair(25, COLOR_BLACK, COLOR_BLUE);
	init_pairs_bis();
}

void		init_tui(t_corewar *c)
{
	int ch;

	c->cycles_per_s = 50;
	c->tui_proc0 = -1;
	initscr();
	raw();
	noecho();
	cbreak();
	timeout(0);
	curs_set(0);
	keypad(stdscr, 2);
	start_color();
	init_pairs();
	ch = (int)' ' | COLOR_PAIR(100);
	hline(ch, (ft_sqrt(MEM_SIZE) * 3) + 58);
	vline(ch, ft_sqrt(MEM_SIZE) + 2);
	mvhline(ft_sqrt(MEM_SIZE) + 1, 0, ch, (ft_sqrt(MEM_SIZE) * 3) + 58);
	mvvline(0, ft_sqrt(MEM_SIZE) * 3 + 2, ch, ft_sqrt(MEM_SIZE) + 2);
	mvvline(0, ft_sqrt(MEM_SIZE) * 3 + 58, ch, ft_sqrt(MEM_SIZE) + 2);
}
