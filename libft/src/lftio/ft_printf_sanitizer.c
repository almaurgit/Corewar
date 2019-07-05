/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sanitizer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 01:18:12 by efouille          #+#    #+#             */
/*   Updated: 2019/06/04 17:07:38 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include "lftmath.h"

static int	get_compatible_flags(char conv)
{
	int	cmp[128];

	cmp['c'] = F_MINUS;
	cmp['s'] = F_MINUS;
	cmp['p'] = F_ZERO | F_MINUS | F_PLUS | F_SPACE;
	cmp['d'] = F_ZERO | F_MINUS | F_PLUS | F_SPACE | F_QUOTE;
	cmp['i'] = cmp['d'];
	cmp['o'] = F_HASH | F_ZERO | F_MINUS | F_PLUS;
	cmp['u'] = F_ZERO | F_MINUS | F_QUOTE;
	cmp['x'] = F_HASH | F_ZERO | F_MINUS | F_PLUS | F_SPACE;
	cmp['X'] = cmp['x'];
	cmp['f'] = F_HASH | F_ZERO | F_MINUS | F_PLUS | F_SPACE | F_QUOTE;
	cmp['F'] = cmp['f'];
	cmp['b'] = F_HASH | F_ZERO | F_MINUS | F_PLUS | F_SPACE | F_QUOTE;
	cmp['B'] = cmp['b'];
	cmp['n'] = F_NONE;
	cmp['%'] = F_ZERO | F_MINUS;
	cmp['k'] = F_NONE;
	return (cmp[(int)conv]);
}

static void	convert_big_csdou(t_fmt *fmt)
{
	int	is_big;

	is_big = fmt->conversion == 'C';
	is_big += fmt->conversion == 'S';
	is_big += fmt->conversion == 'D';
	is_big += fmt->conversion == 'O';
	is_big += fmt->conversion == 'U';
	if (is_big)
	{
		fmt->conversion += 0x20;
		fmt->modifiers = 0x0;
		ft_setbit((t_imax*)&(fmt->modifiers), I_L);
	}
}

void		sanitize_format(t_fmt *fmt)
{
	int	tmp;

	while (fmt)
	{
		if (known_conversion(fmt->conversion))
		{
			convert_big_csdou(fmt);
			fmt->flags &= get_compatible_flags(fmt->conversion);
			tmp = fmt->conversion != 'F' && fmt->conversion != '%';
			if (fmt->precision > 0 && fmt->conversion != 'f' && tmp)
				ft_unsetbit((t_imax*)&(fmt->flags), I_ZERO);
			if (fmt->conversion == 'p')
				ft_setbit((t_imax*)&(fmt->modifiers), I_J);
			tmp = fmt->conversion == 'f' || fmt->conversion == 'F';
			if (fmt->precision == -1 && tmp)
				fmt->precision = 6;
		}
		fmt = fmt->next;
	}
}
