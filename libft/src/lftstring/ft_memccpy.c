/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 23:22:51 by Edgar             #+#    #+#             */
/*   Updated: 2019/03/25 15:19:35 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_types.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	k;

	k = 0;
	while (k < n)
	{
		((t_uchar*)dst)[k] = ((t_uchar*)src)[k];
		if (((t_uchar*)src)[k] == (t_uchar)c)
		{
			((t_uchar*)dst)[k] = ((t_uchar*)src)[k];
			return (&(((char*)dst)[k + 1]));
		}
		k++;
	}
	return (NULL);
}
