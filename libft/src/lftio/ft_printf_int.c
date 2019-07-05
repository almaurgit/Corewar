/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 04:42:18 by efouille          #+#    #+#             */
/*   Updated: 2019/06/04 19:39:50 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include "lftlib.h"
#include "lftmath.h"
#include "lftstring.h"
#include <stdlib.h>

static void	calculate_lens(t_fmt *f, t_printlen *pl, t_umax n, int base)
{
	pl->n_len = (n == 0 && f->precision == 0) ? 0 : ft_log(n, base);
	if (f->flags & F_QUOTE)
		pl->n_len += ft_log(n, base) / (base == 2 ? 4 : 3);
	if (f->flags & F_HASH)
	{
		if (f->conversion == 'p')
			pl->prefix += 2;
		else if ((f->conversion == 'x' || f->conversion == 'X') && n)
			pl->prefix += 2;
		else if ((f->conversion == 'b' || f->conversion == 'B') && n)
			pl->prefix += 2;
		else if (f->conversion == 'o' && n)
			pl->prefix += 1;
	}
	pl->prefix += ((f->flags & F_PLUS) || (f->flags & F_SPACE) || pl->negative);
	if (f->conversion == 'o')
		pl->precision = ft_max(0, f->precision - pl->n_len - pl->prefix);
	else
		pl->precision = ft_max(0, f->precision - pl->n_len);
	pl->tot_len = pl->prefix + pl->n_len + pl->precision;
	pl->padding = ft_max(0, f->width - pl->tot_len);
}

static void	print_uint(t_pfenv *env, t_umax n, int base, int caps)
{
	t_printlen	pl;
	char		*nbr;

	ft_bzero(&pl, sizeof(t_printlen));
	pl.negative = base < 0;
	base = ft_abs(base);
	if (env->cur_fmt->precision || n)
		nbr = ft_utoa_base(n, base, caps, env->cur_fmt->flags & F_QUOTE);
	else if (env->cur_fmt->conversion == 'p' && env->cur_fmt->precision)
		nbr = ft_utoa_base(n, base, caps, env->cur_fmt->flags & F_QUOTE);
	else
		nbr = ft_strnew(0);
	calculate_lens(env->cur_fmt, &pl, n, base);
	print_padding(env, n, &pl, 0);
	print_nchars(env, '0', pl.precision);
	ft_tstrappendstr(env->output, nbr);
	print_padding(env, n, &pl, 1);
	free(nbr);
}

void		print_di(t_pfenv *env)
{
	t_imax	n;

	n = va_arg(env->vl, t_imax);
	cast_int(env, &n);
	print_uint(env, n >= 0 ? n : -n, n >= 0 ? 10 : -10, 0);
}

void		print_poub(t_pfenv *env)
{
	t_umax	n;
	char	conv;

	n = va_arg(env->vl, t_umax);
	conv = env->cur_fmt->conversion;
	cast_uint(env, &n);
	if (conv == 'p')
	{
		ft_setbit((t_imax*)&(env->cur_fmt->flags), 0);
		print_uint(env, n, 16, 0);
	}
	else if (conv == 'o')
	{
		if (env->cur_fmt->flags & F_HASH && !n && !env->cur_fmt->precision)
			env->cur_fmt->precision = -1;
		print_uint(env, n, 8, 0);
	}
	else if (conv == 'b')
		print_uint(env, n, 2, 0);
	else
		print_uint(env, n, 10, 0);
}

void		print_x(t_pfenv *env, int caps)
{
	t_umax	n;

	n = va_arg(env->vl, t_umax);
	cast_uint(env, &n);
	print_uint(env, n, 16, caps);
}
