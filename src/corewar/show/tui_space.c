/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tui_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 22:11:30 by amaurel           #+#    #+#             */
/*   Updated: 2019/05/14 22:54:11 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_space(t_corewar *c)
{
	static int	win = 0;
	int			i;

	i = 0;
	if (win % 2 == 1)
		tui_announce_winner(c);
	else
	{
		while (i < 8)
			mvhline(30 + i++, 61, (int)' ', 73);
		tui_memory(c);
	}
	win++;
}

void	ft_max_cycles(t_corewar *c)
{
	c->cycles_per_s = 1000;
}
