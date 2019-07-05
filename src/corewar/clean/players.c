/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 12:14:38 by efouille          #+#    #+#             */
/*   Updated: 2019/04/19 04:02:43 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_types.h"
#include <stdlib.h>

void	clean_players(t_corewar *c)
{
	int	i;

	i = 0;
	while (i < c->nplayers)
	{
		free(c->players[i]->file->program);
		free(c->players[i]->file);
		free(c->players[i]);
		++i;
	}
	free(c->players);
	c->players = NULL;
}
