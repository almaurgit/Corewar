/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 17:32:46 by Edgar             #+#    #+#             */
/*   Updated: 2019/03/24 10:41:23 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lftstring.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		k;
	int		l;
	char	*dst;

	l = ft_strlen(s1) + 1;
	dst = (char*)malloc(l * sizeof(char));
	if (!dst)
		return (NULL);
	k = 0;
	while (k < l)
	{
		dst[k] = s1[k];
		k++;
	}
	return (dst);
}
