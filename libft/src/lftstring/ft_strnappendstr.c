/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnappendstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 00:53:28 by efouille          #+#    #+#             */
/*   Updated: 2019/03/24 10:53:24 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lftstring.h"
#include <stdlib.h>

char	*ft_strnappendstr(char **s, const char *s2, size_t n)
{
	char	*ret;
	size_t	k;
	size_t	l;

	k = ft_strlen(*s);
	if (!(ret = (char*)malloc((k + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	ft_strcpy(ret, *s);
	l = 0;
	while (s2[l] && l < n)
	{
		ret[k + l] = s2[l];
		l++;
	}
	ret[k + l] = '\0';
	free(*s);
	*s = ret;
	return (*s);
}
