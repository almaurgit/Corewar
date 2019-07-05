/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 23:40:54 by Edgar             #+#    #+#             */
/*   Updated: 2019/03/25 15:20:28 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_types.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	k;

	k = 0;
	if (dst < src)
		while (k < len)
		{
			((t_uchar*)dst)[k] = ((t_uchar*)src)[k];
			k++;
		}
	else
		while (len--)
			((t_uchar*)dst)[len] = ((t_uchar*)src)[len];
	return (dst);
}
