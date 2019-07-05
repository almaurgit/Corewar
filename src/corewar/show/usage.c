/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:03:49 by efouille          #+#    #+#             */
/*   Updated: 2019/05/23 14:33:00 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lftio.h"

void	usage(void)
{
	ft_putendl("|===========================================================|");
	ft_putendl("|  usage: ./corewar [options] <p1.cor> [<p2.cor> <...>]     |");
	ft_putendl("| ---------------------- TEXT OUTPUT ---------------------- |");
	ft_putendl("|  -a / --aff         | prints output from aff              |");
	ft_putendl("|  -d / --dump    n   | runs n cycles, dumps, then exits    |");
	ft_putendl("|  -e / --edump n1 n2 | runs n1 cycles, dumps               |");
	ft_putendl("|                     |   (n2 bytes per line), then exits   |");
	ft_putendl("|  -n / --number  n   | sets the following player's nb to n |");
	ft_putendl("|  -v / --verbose n   | sets verbosity level (can be mixed) |");
	ft_putendl("|                     |   0 | shows only essentials         |");
	ft_putendl("|                     |   1 | shows lives                   |");
	ft_putendl("|                     |   2 | shows cycles                  |");
	ft_putendl("|                     |   4 | shows operations              |");
	ft_putendl("|                     |   8 | shows deaths                  |");
	ft_putendl("|                     |  16 | shows init info               |");
	ft_putendl("| ---------------------- TERMINAL UI ---------------------- |");
	ft_putendl("|  -t / --tui         | enables ncurses terminal ui         |");
	ft_putendl("|===========================================================|");
}
