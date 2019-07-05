/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 17:27:40 by Edgar             #+#    #+#             */
/*   Updated: 2019/03/24 10:48:31 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lftstring.h"
#include <stdlib.h>

char	*ft_strmap(const char *s, char (*f)(char))
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
		ret[k] = f(s[k]);
		k++;
	}
	ret[k] = '\0';
	return (ret);
}
