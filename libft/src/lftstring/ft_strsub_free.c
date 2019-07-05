/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:48:18 by rlegan            #+#    #+#             */
/*   Updated: 2019/05/22 14:43:16 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lftstring.h"
#include <stdlib.h>

char	*ft_strsub_free(char *s, unsigned int start, size_t len)
{
	char	*result;

	if (s)
	{
		if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		{
			ft_strdel(&s);
			return (NULL);
		}
		if (len == 0)
		{
			ft_strdel(&s);
			ft_bzero(result, len + 1);
			return (result);
		}
		ft_strncpy(result, &s[start], len);
		result[len] = '\0';
		ft_strdel(&s);
		return (result);
	}
	return (NULL);
}
