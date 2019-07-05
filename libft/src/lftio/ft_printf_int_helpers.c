/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 01:28:49 by efouille          #+#    #+#             */
/*   Updated: 2019/03/24 10:35:19 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include "lftstring.h"
#include <stdlib.h>
#include <locale.h>

static void	print_sign(t_pfenv *env, int negative)
{
	if (negative && (env->cur_fmt->conversion == 'd'
			|| env->cur_fmt->conversion == 'i'))
		ft_tstrappendchr(env->output, '-');
	else if (env->cur_fmt->flags & F_PLUS)
		ft_tstrappendchr(env->output, '+');
	else if (env->cur_fmt->flags & F_SPACE)
		ft_tstrappendchr(env->output, ' ');
}

static void	print_prefix(t_pfenv *env, t_imax n)
{
	t_fmt	*f;

	f = env->cur_fmt;
	if (f->conversion == 'p')
		ft_tstrappendstr(env->output, "0x");
	else if ((f->flags & F_HASH) && f->conversion == 'x' && n)
		ft_tstrappendstr(env->output, "0x");
	else if ((f->flags & F_HASH) && f->conversion == 'X' && n)
		ft_tstrappendstr(env->output, "0X");
	else if ((f->flags & F_HASH) && f->conversion == 'o' && n)
		ft_tstrappendstr(env->output, "0");
	else if ((f->flags & F_HASH) && f->conversion == 'b' && n)
		ft_tstrappendstr(env->output, "0b");
	else if ((f->flags & F_HASH) && f->conversion == 'B' && n)
		ft_tstrappendstr(env->output, "0B");
}

void		print_padding(t_pfenv *env, t_umax n, t_printlen *pl, int after)
{
	t_fmt	*f;

	f = env->cur_fmt;
	if (!after)
	{
		if ((!(f->flags & F_MINUS) && !(f->flags & F_ZERO)) || !f->precision)
			print_nchars(env, ' ', pl->padding);
		print_sign(env, pl->negative);
		print_prefix(env, n);
		if (f->flags & F_ZERO && !(f->flags & F_MINUS) && f->precision)
			print_nchars(env, '0', pl->padding);
	}
	else if (f->flags & F_MINUS)
		print_nchars(env, ' ', pl->padding);
}
