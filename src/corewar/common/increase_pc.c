/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increase_pc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:47:27 by efouille          #+#    #+#             */
/*   Updated: 2019/05/22 19:55:07 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_const.h"

void	increase_pc(int *pc, int n)
{
	*pc += n;
	*pc %= MEM_SIZE;
}
