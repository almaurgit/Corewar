/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 00:53:28 by efouille          #+#    #+#             */
/*   Updated: 2019/03/24 10:35:42 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include "lftstring.h"
#include <stdlib.h>

static int	calculate_len(int c)
{
	if (c <= 0x7f)
		return (1);
	else if (c <= 0x7ff)
		return (2);
	else if (c <= 0xffff)
		return (3);
	else if (c <= 0x10ffff)
		return (4);
	else
		return (0);
}

void		print_c(t_pfenv *env)
{
	int		c;
	int		len;
	char	*tmp;

	c = env->cur_fmt->unknown ? env->cur_fmt->unknown : va_arg(env->vl, int);
	if ((env->stop = (env->cur_fmt->modifiers & M_L && c < 0)))
		return ;
	len = calculate_len(c);
	if (env->cur_fmt->width && !(env->cur_fmt->flags & F_MINUS))
		print_nchars(env, ' ', env->cur_fmt->width - len);
	if (env->cur_fmt->modifiers & M_L && c >= 0x80)
	{
		if (!(tmp = ft_wchartostr(c)))
		{
			env->stop = 1;
			return ;
		}
		ft_tstrappendstr(env->output, tmp);
		free(tmp);
	}
	else
		ft_tstrappendchr(env->output, c);
	if (env->cur_fmt->width && (env->cur_fmt->flags & F_MINUS))
		print_nchars(env, ' ', env->cur_fmt->width - len);
}

static char	*get_wstring(int *va, int precision)
{
	char	*ret;
	char	*tmp;
	int		k;
	int		ignore_precision;

	if (!va)
		return (NULL);
	ret = ft_strnew(0);
	k = 0;
	ignore_precision = (precision == -1);
	while (va[k] && (precision >= calculate_len(va[k]) || ignore_precision))
	{
		tmp = ft_wchartostr(va[k]);
		if (!tmp)
		{
			free(ret);
			return (NULL);
		}
		ft_strappendstr(&ret, tmp);
		free(tmp);
		precision -= calculate_len(va[k]);
		++k;
	}
	return (ret);
}

void		print_s(t_pfenv *env)
{
	char	*s;
	int		s_was_null;
	int		width_size;
	int		size;
	int		precision_size;

	s = env->cur_fmt->modifiers & M_L
			? get_wstring(va_arg(env->vl, int*), env->cur_fmt->precision)
			: va_arg(env->vl, char*);
	s_was_null = s ? 0 : 1;
	if (s_was_null)
		s = ft_strdup("(null)");
	size = ft_strlen(s);
	precision_size = env->cur_fmt->precision;
	width_size = env->cur_fmt->width;
	if (precision_size >= 0 && precision_size < size)
		size = precision_size;
	if (width_size > size && !(env->cur_fmt->flags & F_MINUS))
		print_nchars(env, ' ', width_size - size);
	ft_tstrnappendstr(env->output, s, size);
	if (width_size > size && (env->cur_fmt->flags & F_MINUS))
		print_nchars(env, ' ', width_size - size);
	if (s_was_null || (env->cur_fmt->modifiers & M_L))
		free(s);
}

void		print_percent(t_pfenv *env)
{
	int		width_size;

	width_size = env->cur_fmt->width < 1 ? 0 : env->cur_fmt->width - 1;
	if (!(env->cur_fmt->flags & F_MINUS) && !(env->cur_fmt->flags & F_ZERO))
		print_nchars(env, ' ', width_size);
	else if (!(env->cur_fmt->flags & F_MINUS) && (env->cur_fmt->flags & F_ZERO))
		print_nchars(env, '0', width_size);
	ft_tstrappendchr(env->output, '%');
	if (env->cur_fmt->flags & F_MINUS)
		print_nchars(env, ' ', width_size);
}
