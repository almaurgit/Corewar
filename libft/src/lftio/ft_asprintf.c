/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:42:30 by efouille          #+#    #+#             */
/*   Updated: 2019/03/23 23:44:19 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include "lftmath.h"
#include "lftstring.h"

static void			get_stars(t_pfenv *env)
{
	int	width;
	int	precision;

	if (env->cur_fmt->width == -2)
	{
		width = va_arg(env->vl, int);
		if (width >= 0)
			env->cur_fmt->width = width;
		else
		{
			env->cur_fmt->width = -width;
			ft_setbit((t_imax*)&(env->cur_fmt->flags), 2);
		}
	}
	if (env->cur_fmt->precision == -2)
	{
		precision = va_arg(env->vl, int);
		env->cur_fmt->precision = precision >= -1 ? precision : -1;
	}
}

static void			print(t_pfenv *env)
{
	int			printer;

	while (env->cur_fmt && !env->stop)
	{
		get_stars(env);
		printer = env->cur_fmt->conversion;
		if (printer >= 0 && printer < 128 && env->printers[printer])
		{
			if (env->cur_fmt->conversion == 'n')
				*(va_arg(env->vl, int*)) = env->output->len;
			else
				(env->printers[printer])(env, (env->cur_fmt->conversion == 'X'
					|| env->cur_fmt->conversion == 'B'));
			if (!env->stop)
				ft_tstrappendstr(env->output, env->cur_fmt->str_next);
		}
		env->cur_fmt = env->cur_fmt->next;
	}
}

int					ft_vasprintf(char **str, const char *format, va_list vl)
{
	t_pfenv	*env;
	t_str	*s;
	int		first_percent;
	int		printed;

	if ((first_percent = ft_index_of(format, '%')) == -1)
	{
		*str = ft_strnew(ft_strlen(format));
		ft_strappendstr(str, format);
		return (ft_strlen(format));
	}
	s = ft_tstrnew(0);
	ft_tstrnappendstr(s, format, first_percent);
	if (!(env = create_env(format, ft_parse_args(format), s, vl)))
		return (-1);
	sanitize_format(env->formats);
	print(env);
	*str = ft_strnew(s->len);
	ft_memcpy(*str, s->str, s->len);
	printed = env->stop ? -1 : (int)s->len;
	ft_tstrdel(&s);
	clean_all(env);
	return (printed);
}

int					ft_asprintf(char **str, const char *format, ...)
{
	int		size;
	va_list	vl;

	va_start(vl, format);
	size = ft_vasprintf(str, format, vl);
	va_end(vl);
	return (size);
}
