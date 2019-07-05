/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 16:43:55 by Edgar             #+#    #+#             */
/*   Updated: 2019/03/24 10:47:56 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lftstring.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len1;
	int		len2;
	int		k;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ret = (char*)malloc((len1 + len2 + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	k = 0;
	while (s1[k])
	{
		ret[k] = s1[k];
		k++;
	}
	while (s2[k - len1])
	{
		ret[k] = s2[k - len1];
		k++;
	}
	ret[k] = '\0';
	return (ret);
}
