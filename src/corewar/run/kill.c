/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:00:10 by efouille          #+#    #+#             */
/*   Updated: 2019/05/28 07:44:53 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "ft_printf.h"
#include "libft_const.h"

static void	kill_procs(t_corewar *c)
{
	int	i;

	i = (int)c->nprocs - 1;
	while (i >= 0)
	{
		if (c->procs[i] && !c->procs[i]->living)
		{
			clean_proc(c, i);
			--(c->nliving);
			if (c->verbose & V_DEATHS)
				ft_printf("%sproc %d died%s\n", SH_RED, i, SH_DEFAULT);
		}
		else if (c->procs[i])
			c->procs[i]->living = 0;
		--i;
	}
}

void		kill(t_corewar *c)
{
	kill_procs(c);
	++(c->nb_checks);
	if (c->total_live >= NBR_LIVE || c->nb_checks >= MAX_CHECKS)
	{
		c->cycles_to_die -= CYCLE_DELTA;
		c->nb_checks = 0;
	}
	c->total_live = 0;
	c->next_kill = c->cycles + c->cycles_to_die;
}
