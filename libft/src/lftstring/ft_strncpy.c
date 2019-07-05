/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 17:57:49 by Edgar             #+#    #+#             */
/*   Updated: 2019/03/25 15:21:58 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_types.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	k;

	k = 0;
	while (src[k] && k < len)
	{
		dst[k] = src[k];
		k++;
	}
	while (k < len)
		dst[k++] = '\0';
	return (dst);
}
