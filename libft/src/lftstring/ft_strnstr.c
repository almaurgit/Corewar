/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 22:37:49 by Edgar             #+#    #+#             */
/*   Updated: 2019/06/04 17:18:43 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lftstring.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	j;
	size_t	k;
	size_t	l;

	j = ft_strlen(n);
	if (j == 0)
		return ((char*)h);
	k = 0;
	while (h[k])
	{
		l = 0;
		while (((l <= j && n[l] == h[k + l]) || n[l] == '\0') && (k + l) <= len)
		{
			if (n[l] == '\0')
				return ((char*)&(h[k]));
			l++;
		}
		k++;
	}
	return (NULL);
}
