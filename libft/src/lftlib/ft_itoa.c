/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 19:26:35 by Edgar             #+#    #+#             */
/*   Updated: 2019/03/25 15:25:59 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lftmath.h"
#include "lftstring.h"
#include <stdlib.h>

static void	init_itoa(long *n, int *neg, int *len)
{
	*neg = (*n < 0) ? 1 : 0;
	if (*neg)
		*n = -(*n);
	*len = ft_log(*n, 10);
}

char		*ft_itoa(long n)
{
	char	*ret;
	int		neg;
	int		len;
	int		k;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	init_itoa(&n, &neg, &len);
	ret = (char*)malloc((len + 1 + neg) * sizeof(char));
	if (!ret)
		return (NULL);
	k = 0;
	while (n > 0)
	{
		ret[k++] = (n % 10) + '0';
		n /= 10;
	}
	if (neg)
		ret[k++] = '-';
	ret[k] = '\0';
	ret = ft_strrev(ret);
	ret[k] = '\0';
	return (ret);
}
