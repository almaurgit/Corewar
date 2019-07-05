/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 02:50:10 by efouille          #+#    #+#             */
/*   Updated: 2019/03/25 15:18:20 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_types.h"
#include <stdlib.h>

static void	*ft_matfree(t_matrix *mat)
{
	int	k;

	k = -1;
	if (mat)
	{
		if (mat->m)
		{
			while (mat->m[++k])
				free(mat->m[k]);
			free(mat->m);
		}
		free(mat);
	}
	return (NULL);
}

t_matrix	*ft_matnew(int w, int h)
{
	t_matrix	*mat;
	int			k;

	if (!(mat = (t_matrix*)malloc(sizeof(t_matrix))))
		return (ft_matfree(mat));
	mat->w = w;
	mat->h = h;
	if (!(mat->m = (float**)malloc(h * sizeof(float*))))
		return (ft_matfree(mat));
	k = 0;
	while (k < h)
	{
		if (!(mat->m[k] = (float*)malloc(w * sizeof(float))))
			return (ft_matfree(mat));
		k++;
	}
	return (mat);
}
