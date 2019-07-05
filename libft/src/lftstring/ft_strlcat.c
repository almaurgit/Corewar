/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 18:29:35 by Edgar             #+#    #+#             */
/*   Updated: 2019/03/24 10:46:44 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lftstring.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	k;
	size_t	l;

	if (size == 0)
		return (ft_strlen(src));
	k = 0;
	while (dst[k] && k < size)
		k++;
	l = k;
	while (src[k - l] && k < size - 1)
	{
		dst[k] = src[k - l];
		k++;
	}
	if (l < size)
		dst[k] = '\0';
	return (l + ft_strlen(src));
}
