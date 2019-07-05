/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_ch.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:16:01 by amaurel           #+#    #+#             */
/*   Updated: 2019/05/29 18:40:37 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "lftstring.h"

void	ft_increase_cps(t_corewar *c)
{
	if (c->cycles_per_s <= 990)
		c->cycles_per_s += 10;
	else
		c->cycles_per_s = 1000;
}

void	ft_increase_cps1(t_corewar *c)
{
	if (c->cycles_per_s <= 999)
		++c->cycles_per_s;
}

void	ft_decrease_cps(t_corewar *c)
{
	if (c->cycles_per_s > 10)
		c->cycles_per_s -= 10;
	else
		c->cycles_per_s = 1;
}

void	ft_decrease_cps1(t_corewar *c)
{
	if (c->cycles_per_s >= 2)
		--c->cycles_per_s;
}

void	ft_next_cycle(t_corewar *c)
{
	if (c->tui_pause)
	{
		ft_memset(c->pc, -1, MEM_SIZE);
		run_step(c);
		++(c->cycles);
	}
}
