/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapbytes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:23:21 by efouille          #+#    #+#             */
/*   Updated: 2019/04/18 01:50:59 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_types.h"

void	ft_swapbytes(t_u8 *bytes, t_uint n)
{
	t_u8	tmp;
	t_u8	i;

	i = 0;
	while (i < n / 2)
	{
		tmp = bytes[n - i - 1];
		bytes[n - i - 1] = bytes[i];
		bytes[i] = tmp;
		++i;
	}
}
