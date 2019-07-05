/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 03:45:28 by efouille          #+#    #+#             */
/*   Updated: 2019/03/25 15:18:01 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_types.h"
#include <stdlib.h>

void	ft_matdel(t_matrix **a)
{
	t_matrix	*mat;
	int			k;

	if (a)
	{
		if (*a)
		{
			mat = *a;
			k = 0;
			while (k < mat->h)
			{
				free(mat->m[k]);
				k++;
			}
			free(mat->m);
			free(*a);
			*a = NULL;
		}
	}
}
