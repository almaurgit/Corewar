/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 18:47:14 by efouille          #+#    #+#             */
/*   Updated: 2019/03/25 15:22:41 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_types.h"
#include <stdlib.h>

char	*ft_strsub(const char *s, t_uint start, size_t len)
{
	char	*ret;
	int		k;

	if (!s)
		return (NULL);
	ret = (char*)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	k = start;
	while (k - start < len)
	{
		ret[k - start] = s[k];
		k++;
	}
	ret[k - start] = '\0';
	return (ret);
}
