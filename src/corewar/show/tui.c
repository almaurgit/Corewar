/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:13:52 by amaurel           #+#    #+#             */
/*   Updated: 2019/06/04 19:59:48 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "lftmath.h"
#include <ncurses.h>

t_getch		*f_getch(void)
{
	static t_getch		getch[11];

	getch[0].ch = 4;
	getch[0].f_ch = &ft_decrease_cps;
	getch[1].ch = 2;
	getch[1].f_ch = &ft_decrease_cps1;
	getch[2].ch = 3;
	getch[2].f_ch = &ft_increase_cps1;
	getch[3].ch = 5;
	getch[3].f_ch = &ft_increase_cps;
	getch[4].ch = 'p';
	getch[4].f_ch = &ft_procs;
	getch[5].ch = 's';
	getch[5].f_ch = &ft_cancel_procs;
	getch[6].ch = 'h';
	getch[6].f_ch = &ft_help;
	getch[7].ch = 'n';
	getch[7].f_ch = &ft_next_cycle;
	getch[8].ch = ' ';
	getch[8].f_ch = &ft_space;
	getch[9].ch = 'm';
	getch[9].f_ch = &ft_max_cycles;
	getch[10].ch = 0;
	getch[10].f_ch = &ft_decrease_cps1;
	return (getch);
}

static void	print_byte(t_corewar *c, int ij)
{
	int	owner;
	int	pc_here;

	owner = c->owner[ij] % 4 + 1;
	pc_here = c->pc[ij] % 4;
	if (pc_here >= 0)
		owner += 10 * (pc_here + 1);
	attron(COLOR_PAIR(owner));
	printw("%02x", c->mem[ij]);
	attroff(COLOR_PAIR(owner));
}

void		tui_memory(t_corewar *c)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	move(1, 2);
	size = (int)ft_sqrt(MEM_SIZE);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			move(i + 1, 3 * j + 2);
			print_byte(c, i * size + j);
			++j;
		}
		++i;
		if (i < size)
			move(i + 1, 2);
	}
}

int			tui(t_corewar *c, t_u8 end)
{
	tui_memory(c);
	if (!tui_info(c, 0))
		return (0);
	if (end)
	{
		tui_announce_winner(c);
		while (1)
		{
			if (!tui_info(c, 1))
				return (1);
		}
	}
	if (c->tui_proc0 >= 0)
		ft_procs(c);
	if (c->cycles_per_s < 500)
		timeout(1000 / c->cycles_per_s);
	else
		timeout(0);
	return (1);
}
