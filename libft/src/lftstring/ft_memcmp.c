/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 00:11:49 by Edgar             #+#    #+#             */
/*   Updated: 2019/03/25 15:20:07 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_types.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	k;

	k = 0;
	while (k < n)
	{
		if (((t_uchar*)s1)[k] != ((t_uchar*)s2)[k])
			return ((int)(((t_uchar*)s1)[k] - ((t_uchar*)s2)[k]));
		k++;
	}
	return (0);
}
