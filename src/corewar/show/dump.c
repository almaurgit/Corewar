/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:46:25 by efouille          #+#    #+#             */
/*   Updated: 2019/05/27 18:55:53 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_types.h"
#include "lftio.h"
#include "ft_printf.h"
#include "libft_const.h"
#include <unistd.h>

static int	pc_here(t_corewar *c, int n)
{
	int	i;

	i = 0;
	while (i < c->nprocs)
	{
		if (c->procs[i] && c->procs[i]->pc == n)
			return (1);
		++i;
	}
	return (0);
}

static char	**colors(void)
{
	static char	*col[5];

	col[0] = SH_DARKGRAY;
	col[1] = SH_GREEN;
	col[2] = SH_BLUE;
	col[3] = SH_RED;
	col[4] = SH_YELLOW;
	return (col);
}

static void	dump_line(t_corewar *c, int bpl, int i)
{
	int	j;
	int	index;

	j = 0;
	while (j < bpl)
	{
		index = i * bpl + j;
		ft_putstr(colors()[c->owner[index] % 4 + 1]);
		if (pc_here(c, index))
			ft_putstr("\e[44m");
		ft_printf("%02x", c->mem[index]);
		if (pc_here(c, index))
			ft_putstr("\e[49m");
		ft_putchar(' ');
		ft_putstr(SH_DEFAULT);
		++j;
	}
}

static void	dump_last_line(t_corewar *c, int start)
{
	int	i;

	i = start;
	while (i < MEM_SIZE)
	{
		ft_putstr(colors()[c->owner[i] % 4 + 1]);
		if (pc_here(c, i))
			ft_putstr("\e[44m");
		ft_printf("%02x", c->mem[i]);
		if (pc_here(c, i))
			ft_putstr("\e[49m");
		ft_putchar(' ');
		ft_putstr(SH_DEFAULT);
		++i;
	}
}

void		dump(t_corewar *c, int bytes_per_line)
{
	int	i;

	ft_putstr(SH_ERASE);
	i = 0;
	while (i < MEM_SIZE / bytes_per_line)
	{
		ft_printf("0x%04x : ", i * bytes_per_line);
		dump_line(c, bytes_per_line, i);
		ft_putchar('\n');
		++i;
	}
	if (MEM_SIZE % bytes_per_line)
	{
		ft_printf("0x%04x : ", i * bytes_per_line);
		dump_last_line(c, i * bytes_per_line);
		ft_putchar('\n');
	}
	ft_putchar('\n');
}
