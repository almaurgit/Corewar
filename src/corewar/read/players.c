/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:11:22 by efouille          #+#    #+#             */
/*   Updated: 2019/05/21 23:31:45 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_types.h"
#include <stdlib.h>

static int	unused_number(t_corewar *c, int n)
{
	int	i;

	i = 0;
	while (i < c->nplayers - 1)
	{
		if (c->players[i]->number == n)
			return (0);
		++i;
	}
	return (1);
}

static int	get_number_player(t_corewar *c)
{
	int	n;

	n = 0;
	while (n < c->nplayers + 1)
	{
		if (unused_number(c, n + 1))
			return (n + 1);
		++n;
	}
	return (c->nplayers);
}

int			add_player(t_corewar *c, t_corfile *cf)
{
	int			new_size;
	t_player	**players;
	t_player	*player;

	c->nplayers = c->nplayers + 1 > 0 ? c->nplayers + 1 : 1;
	new_size = c->nplayers * sizeof(t_player*);
	if (!(players = (t_player**)realloc(c->players, new_size)))
		return (cw_malloc_error);
	c->players = players;
	if (!(player = (t_player*)malloc(sizeof(t_player))))
		return (cw_malloc_error);
	player->file = cf;
	player->name = cf->header.prog_name;
	player->last_live = 0;
	c->players[c->nplayers - 1] = player;
	if (c->flagnumber)
	{
		if (!unused_number(c, c->number_next_player))
			return (cw_number_error);
		player->number = c->number_next_player;
		c->flagnumber = 0;
	}
	else
		player->number = get_number_player(c);
	return (0);
}
