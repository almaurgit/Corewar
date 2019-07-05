/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 02:50:54 by efouille          #+#    #+#             */
/*   Updated: 2019/04/13 02:56:07 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_types.h"

void	read_mem(t_corewar *c, int src, t_u8 *bytes, int size)
{
	int	i;

	while (src < 0)
		src += MEM_SIZE;
	if (src >= MEM_SIZE)
		src %= MEM_SIZE;
	i = 0;
	while (i < size)
	{
		bytes[i] = c->mem[(src + i) % MEM_SIZE];
		++i;
	}
}
