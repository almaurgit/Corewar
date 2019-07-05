/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matprod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 03:34:24 by efouille          #+#    #+#             */
/*   Updated: 2019/03/25 14:53:20 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lftmath.h"

static void	process_prod(t_matrix *c, t_matrix *a, t_matrix *b)
{
	int		i;
	int		j;
	int		k;
	float	s;

	i = 0;
	while (i < a->h)
	{
		j = 0;
		while (j < a->w)
		{
			k = 0;
			s = 0;
			while (k < a->w)
			{
				s += a->m[i][k] * b->m[k][j];
				k++;
			}
			c->m[i][j] = s;
			j++;
		}
		i++;
	}
}

t_matrix	*ft_matprod(t_matrix *a, t_matrix *b)
{
	t_matrix	*c;

	if (!a || !b)
		return (NULL);
	if (a->w != b->h)
		return (NULL);
	if (!(c = ft_matnew(a->w, a->w)))
		return (NULL);
	process_prod(c, a, b);
	return (c);
}
