/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfmantissa_dec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 19:26:35 by Edgar             #+#    #+#             */
/*   Updated: 2019/03/25 15:27:02 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lftmath.h"

int	ft_getfmantissa_dec(float n)
{
	float	m;
	int		k;
	int		pow;

	m = 0.0;
	k = 23;
	pow = 0;
	while (k >= 0)
	{
		m += ft_getfbit(n, k) / (float)pow;
		pow *= 2;
		--k;
	}
	return ((int)m);
}
