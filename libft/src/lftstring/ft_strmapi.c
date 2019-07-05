/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 17:44:00 by Edgar             #+#    #+#             */
/*   Updated: 2019/03/24 10:48:46 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lftstring.h"
#include <stdlib.h>

char	*ft_strmapi(const char *s, char (*f)(int, char))
{
	char	*ret;
	int		slen;
	int		k;

	if (!s)
		return (NULL);
	slen = ft_strlen(s) + 1;
	ret = (char*)malloc(slen * sizeof(char));
	if (!ret)
		return (NULL);
	k = 0;
	while (k < slen - 1)
	{
		ret[k] = f(k, s[k]);
		k++;
	}
	ret[k] = '\0';
	return (ret);
}
