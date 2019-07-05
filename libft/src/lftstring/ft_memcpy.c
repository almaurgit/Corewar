/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 23:11:02 by Edgar             #+#    #+#             */
/*   Updated: 2019/03/25 15:20:19 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_types.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	k;
	size_t	uk;

	k = 0;
	uk = 0;
	while (k + sizeof(t_umax) < n)
	{
		((t_umax*)dst)[uk] = ((t_umax*)src)[uk];
		k += sizeof(t_umax);
		uk += 1;
	}
	while (k < n)
	{
		((t_uchar*)dst)[k] = ((t_uchar*)src)[k];
		k += 1;
	}
	return (dst);
}
