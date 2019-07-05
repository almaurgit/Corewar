/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 03:23:54 by efouille          #+#    #+#             */
/*   Updated: 2019/03/25 14:52:03 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lftmath.h"

t_matrix	*ft_matadd(t_matrix *a, t_matrix *b)
{
	t_matrix	*c;
	int			i;
	int			j;

	if (!a || !b)
		return (NULL);
	if (a->w != b->w || a->h != b->h)
		return (NULL);
	c = ft_matnew(a->w, a->h);
	i = 0;
	while (i < a->h)
	{
		j = 0;
		while (j < a->w)
		{
			c->m[i][j] = a->m[i][j] + b->m[i][j];
			j++;
		}
		i++;
	}
	return (c);
}
