/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 02:37:15 by efouille          #+#    #+#             */
/*   Updated: 2019/04/13 02:52:57 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_types.h"

void	write_mem(t_corewar *c, int dst, t_u8 *bytes, int size)
{
	int	i;

	while (dst < 0)
		dst += MEM_SIZE;
	if (dst >= MEM_SIZE)
		dst %= MEM_SIZE;
	i = 0;
	while (i < size)
	{
		c->mem[(dst + i) % MEM_SIZE] = bytes[i];
		++i;
	}
}

void	write_owner(t_corewar *c, int dst, int player, int size)
{
	int	i;

	while (dst < 0)
		dst += MEM_SIZE;
	if (dst >= MEM_SIZE)
		dst %= MEM_SIZE;
	i = 0;
	while (i < size)
	{
		c->owner[(dst + i) % MEM_SIZE] = player;
		++i;
	}
}
