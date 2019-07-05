/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:29:26 by efouille          #+#    #+#             */
/*   Updated: 2019/05/27 18:57:49 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "lftio.h"
#include "ft_printf.h"
#include "libft_const.h"

/*
** instruction live from corewar assembly language
**
** instruction args
**		(direct)	arg0 - the player number to set alive
**
** tells the vm that player arg0 is alive and that the calling process is alive
**
** func input	: c	- the corewar structure
**				  i	- the caller exec
**
** func output	: none
*/

static void	v_live(int i, t_player *player)
{
	ft_printf("process %d ", i);
	ft_printf("tells \"player %d ", player->number);
	ft_printf("(%s) is alive !\"\n", player->name);
}

void		cw_live(t_corewar *c, int i)
{
	t_args		*a;
	t_process	*p;
	int			j;

	a = c->procs[i]->exec->a;
	if (invalid_args(c->procs[i]->exec->opcode, a))
		return ;
	p = c->procs[i];
	p->living = 1;
	j = 0;
	while (j < c->nplayers)
	{
		if (c->players[j]->number == get_arg(c, i, 0, USE_VALUE))
		{
			c->players[j]->last_live = c->cycles;
			if (c->verbose & V_LIVES)
				v_live(i, c->players[j]);
			break ;
		}
		++j;
	}
	++(c->total_live);
	if (c->verbose & V_OP)
		verbose(c, i);
}
