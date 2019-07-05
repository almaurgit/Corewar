/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 00:53:28 by efouille          #+#    #+#             */
/*   Updated: 2019/03/25 15:04:18 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include "lftlib.h"
#include "lftstring.h"
#include <stdlib.h>

static void	print_double_base(t_pfenv *env, long double n)
{
	char	*nbr;
	int		len;

	nbr = ft_dtoa(n, env->cur_fmt->precision, env->cur_fmt->flags & F_QUOTE);
	len = ft_strlen(nbr);
	if (!(env->cur_fmt->flags & F_MINUS) && !(env->cur_fmt->flags & F_ZERO))
		print_nchars(env, ' ', env->cur_fmt->width - len);
	if (n < 0)
	{
		ft_tstrappendchr(env->output, '-');
		n = -n;
	}
	else if (env->cur_fmt->flags & F_PLUS && n >= 0)
		ft_tstrappendchr(env->output, '+');
	else if (env->cur_fmt->flags & F_SPACE && n >= 0)
		ft_tstrappendchr(env->output, ' ');
	if (env->cur_fmt->flags & F_ZERO && !(env->cur_fmt->flags & F_MINUS))
		print_nchars(env, '0', env->cur_fmt->width - len);
	free(nbr);
	nbr = ft_dtoa(n, env->cur_fmt->precision, env->cur_fmt->flags & F_QUOTE);
	ft_tstrappendstr(env->output, nbr);
	if (env->cur_fmt->flags & F_MINUS)
		print_nchars(env, ' ', env->cur_fmt->width - len);
	free(nbr);
}

void		print_dbl(t_pfenv *env)
{
	long double	n;

	if (env->cur_fmt->modifiers & M_LLL)
		n = va_arg(env->vl, long double);
	else
		n = va_arg(env->vl, double);
	print_double_base(env, n);
}
