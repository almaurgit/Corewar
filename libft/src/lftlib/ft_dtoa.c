/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 19:26:35 by Edgar             #+#    #+#             */
/*   Updated: 2019/06/04 17:12:33 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lftlib.h"
#include "lftstring.h"
#include <stdlib.h>

static int	int_part(char **str, long double *n, int s, int p)
{
	t_umax		integer_part;
	long double	tmp;
	int			round;
	char		*int_str;

	integer_part = (t_umax)(*n);
	tmp = *n - integer_part;
	round = (p > 0);
	while (p)
	{
		tmp *= 10;
		if ((t_umax)tmp != 9)
			round = 0;
		tmp -= (t_umax)tmp;
		--p;
	}
	int_str = ft_utoa_base(integer_part + round, 10, 0, s);
	ft_strappendstr(str, int_str);
	free(int_str);
	*n = *n - integer_part;
	return (round);
}

static void	dec_part(char **str, long double n, int p, int no_round)
{
	int	k;

	if (n > 0 && !no_round)
	{
		ft_strappendchr(str, '.');
		k = -1;
		while (++k < p)
			n *= 10;
		if ((n - (t_umax)n) >= 0.5)
			n++;
		int_part(str, &n, 0, 0);
	}
	else
	{
		ft_strappendchr(str, '.');
		while (p--)
			ft_strappendchr(str, '0');
	}
}

/*
** returns 1 if nan, -1 if inf, -2 if -inf, 0 otherwise
*/

static int	nan_inf(long double n)
{
	t_ldouble	*d;

	d = (t_ldouble*)&n;
	if (d->exponent == 0x7FFF)
	{
		if (d->mantissa == 0x3FFFFFFFFFFFFFFF)
			return (1);
		else if (d->mantissa >> 62 == 0x01)
			return (1);
		else if (d->mantissa == 0xBFFFFFFFFFFFFFFF)
			return (1);
		else if (d->mantissa == 0xC000000000000000)
			return (1);
		else if (d->mantissa == 0xFFFFFFFFFFFFFFFF)
			return (1);
		if (d->mantissa == 0x0000000000000000)
			return (d->sign ? -2 : -1);
		else if (d->mantissa == 0x8000000000000000)
			return (d->sign ? -2 : -1);
	}
	return (0);
}

static int	is_negative(long double n)
{
	return (((t_ldouble*)&n)->sign);
}

char		*ft_dtoa(long double n, int p, int s)
{
	char	*str;
	int		neg;
	int		d_nan_inf;
	int		rounded_int_part;

	d_nan_inf = nan_inf(n);
	if (d_nan_inf == 1)
		return (ft_strdup("nan"));
	else if (d_nan_inf == -1)
		return (ft_strdup("inf"));
	else if (d_nan_inf == -2)
		return (ft_strdup("-inf"));
	if ((neg = is_negative(n)))
		n = -n;
	str = ft_strnew(0);
	if (p <= 0 && (n - (t_umax)n) >= 0.5)
		n++;
	rounded_int_part = int_part(&str, &n, s, p);
	if (p > 0)
		dec_part(&str, n, p, rounded_int_part);
	if (neg)
		ft_strins(&str, '-', 0);
	return (str);
}
