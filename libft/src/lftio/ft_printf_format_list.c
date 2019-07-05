/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 00:16:10 by efouille          #+#    #+#             */
/*   Updated: 2019/03/25 15:02:49 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include "lftlib.h"
#include "lftstring.h"
#include <stdlib.h>

t_fmt	*fmt_new(void)
{
	t_fmt	*fmt;

	if (!(fmt = (t_fmt*)ft_memalloc(sizeof(t_fmt))))
		return (NULL);
	fmt->precision = -1;
	return (fmt);
}

void	fmt_append(t_fmt **fmt, t_fmt *new)
{
	t_fmt	*k;

	if (fmt)
	{
		if (*fmt && new)
		{
			k = *fmt;
			while (k->next)
				k = k->next;
			k->next = new;
		}
		else if (new)
		{
			*fmt = new;
		}
	}
}

void	fmt_clear(t_fmt **fmt)
{
	t_fmt	*tmp;
	t_fmt	*k;

	if (fmt)
	{
		if (*fmt)
		{
			k = *fmt;
			while (k)
			{
				tmp = k->next;
				ft_strdel(&(k->str_next));
				ft_memdel((void**)&k);
				k = tmp;
			}
			*fmt = NULL;
		}
	}
}
