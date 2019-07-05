/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstrappendstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 04:36:29 by efouille          #+#    #+#             */
/*   Updated: 2019/03/24 10:51:51 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lftstring.h"
#include <stdlib.h>

t_str	*ft_tstrappendstr(t_str *s, const char *s2)
{
	char	*tmp;
	size_t	l;

	if (!(tmp = (char*)malloc((s->len + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	ft_memcpy(tmp, s->str, s->len);
	l = 0;
	while (s2[l])
		tmp[s->len++] = s2[l++];
	tmp[s->len] = '\0';
	free(s->str);
	s->str = tmp;
	return (s);
}
