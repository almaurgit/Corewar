/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introduce.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:07:56 by efouille          #+#    #+#             */
/*   Updated: 2019/05/21 15:07:56 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_types.h"
#include "lftio.h"
#include "ft_printf.h"

void	introduce_contestants(t_corewar *c)
{
	int	i;

	ft_putstr("Introducing contestants...\n");
	i = 0;
	while (i < c->nplayers)
	{
		ft_printf("* Player %d, ", c->players[i]->number);
		ft_printf("weighing %u bytes,", c->players[i]->file->header.prog_size);
		ft_printf(" \"%s\" ", c->players[i]->file->header.prog_name);
		ft_printf("(\"%s\") !\n", c->players[i]->file->header.comment);
		++i;
	}
}
