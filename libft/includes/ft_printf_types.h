/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_types.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:32:15 by efouille          #+#    #+#             */
/*   Updated: 2019/05/14 18:16:44 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TYPES_H
# define FT_PRINTF_TYPES_H

# include "libft_types.h"
# include <stdarg.h>

typedef void	(*t_printer)();

typedef struct	s_fmt
{
	t_u8			flags;
	int				width;
	int				precision;
	t_u8			modifiers;
	char			conversion;
	char			unknown;
	char			*str_next;
	struct s_fmt	*next;
}				t_fmt;

typedef struct	s_pfenv
{
	t_printer	printers[128];
	const char	*format;
	t_fmt		*formats;
	t_fmt		*cur_fmt;
	t_str		*output;
	va_list		vl;
	int			stop;
}				t_pfenv;

typedef struct	s_printlen
{
	int	negative;
	int	n_len;
	int	prefix;
	int	precision;
	int	tot_len;
	int	padding;
}				t_printlen;

#endif
