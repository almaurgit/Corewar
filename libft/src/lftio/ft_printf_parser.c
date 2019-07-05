/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 01:18:12 by efouille          #+#    #+#             */
/*   Updated: 2019/06/04 17:04:25 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include "lftmath.h"
#include "lftstring.h"

static void		get_f_w_p(const char *format, t_fmt *f, int *k, int *start)
{
	while (ft_index_of(FLAGS, format[*k]) > -1)
		ft_setbit((t_imax*)&(f->flags), ft_index_of(FLAGS, format[(*k)++]));
	*start = *k;
	while (ft_index_of(WIDTH, format[*k]) > -1)
	{
		if (format[*k] == '*')
		{
			f->width = -2;
			ft_unsetbit((t_imax*)&(f->flags), I_ZERO);
		}
		(*k)++;
	}
	if (f->width != -2 && ft_index_of(WIDTH, format[*start]) > -1)
		f->width = get_nbr(format, *start, *k);
	*start = *k;
	while (ft_index_of(PRECISION, format[*k]) > -1)
	{
		if (format[*k] == '*')
			f->precision = -2;
		(*k)++;
	}
	if (f->precision != -2 && ft_index_of(PRECISION, format[*start]) > -1)
		f->precision = get_nbr(format, *start + 1, *k);
}

static void		get_conv_flags(const char *format, t_fmt *f, int *k)
{
	while (ft_index_of(MODIFIERS, format[*k]) > -1)
	{
		if (format[*k] == 'h' && !f->modifiers)
		{
			if (format[*k + 1] == 'h')
				ft_setbit((t_imax*)&(f->modifiers), I_HH);
			else
				ft_setbit((t_imax*)&(f->modifiers), I_H);
		}
		if (format[*k] == 'l' && !f->modifiers)
		{
			if (format[*k + 1] == 'l')
				ft_setbit((t_imax*)&(f->modifiers), I_LL);
			else
				ft_setbit((t_imax*)&(f->modifiers), I_L);
		}
		if (format[*k] == 'L' && !f->modifiers)
			ft_setbit((t_imax*)&(f->modifiers), I_LLL);
		if (format[*k] == 'j' && !f->modifiers)
			ft_setbit((t_imax*)&(f->modifiers), I_J);
		if (format[*k] == 'z' && !f->modifiers)
			ft_setbit((t_imax*)&(f->modifiers), I_Z);
		(*k)++;
	}
}

static int		valid_format(const char *format, int k)
{
	while (format[k])
	{
		if (known_conversion(format[k]))
			return (1);
		else if (valid_unknown_conversion(format[k]))
			return (1);
		++k;
	}
	return (0);
}

static t_fmt	*parse_arg(const char *format, int *k, int *start)
{
	t_fmt	*f;

	if (!(f = fmt_new()))
		return (NULL);
	get_f_w_p(format, f, k, start);
	get_conv_flags(format, f, k);
	if (f->conversion)
		return (NULL);
	if (known_conversion(format[*k])
		|| ft_printf_xtra_printer(format[*k], NULL, PRINTF_XTRA_GET))
		f->conversion = format[(*k)++];
	else
	{
		f->conversion = 'c';
		f->unknown = format[(*k)++];
	}
	f->str_next = get_str_next(format, k);
	return (f);
}

t_fmt			*ft_parse_args(const char *format)
{
	t_fmt	*formats;
	t_fmt	*f;
	int		k;
	int		start;

	formats = NULL;
	f = NULL;
	k = -1;
	while (format[++k])
	{
		if (format[k] == '%')
		{
			++k;
			if (valid_format(format, k) && (f = parse_arg(format, &k, &start)))
				fmt_append(&formats, f);
			--k;
		}
	}
	return (formats);
}
