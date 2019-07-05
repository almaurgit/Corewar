/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 03:15:01 by efouille          #+#    #+#             */
/*   Updated: 2019/01/16 01:08:40 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRIVATE_H
# define FT_PRINTF_PRIVATE_H

# include "ft_printf_types.h"
# include "ft_printf_xtra.h"
# include "ft_printf_const.h"

/*
** casters.c
*/
void	cast_uint(t_pfenv *env, t_umax *n);
void	cast_int(t_pfenv *env, t_imax *n);

/*
** checkers.c
*/
int		known_conversion(char c);
int		valid_unknown_conversion(char c);

/*
** env.c
*/
t_pfenv	*create_env(const char *f, t_fmt *fs, t_str *out, va_list vl);
void	clear_env(t_pfenv **env);

/*
** format_list.c
*/
t_fmt	*fmt_new(void);
void	fmt_append(t_fmt **fmt, t_fmt *new);
void	fmt_clear(t_fmt **fmt);

/*
** parser.c
*/
t_fmt	*ft_parse_args(const char *format);

/*
** print_ascii.c
*/
void	print_c(t_pfenv *env);
void	print_s(t_pfenv *env);
void	print_percent(t_pfenv *env);

/*
** print_date.c
*/
void	print_date(t_pfenv *env);

/*
** print_double.c
*/
void	print_dbl(t_pfenv *env);

/*
** print_int.c
*/
void	print_di(t_pfenv *env);
void	print_poub(t_pfenv *env);
void	print_x(t_pfenv *env, int caps);

/*
** print_int_helpers.c
*/
void	print_padding(t_pfenv *env, t_umax n, t_printlen *pl, int after);
void	print_int_separators(t_pfenv *env, char **nbr);

/*
** sanitize.c
*/
void	sanitize_format(t_fmt *fmt);

/*
** tools.c
*/
int		get_nbr(const char *s, int start, int end);
char	*get_str_next(const char *s, int *k);
void	clean_all(t_pfenv *env);
void	print_nchars(t_pfenv *env, char c, int n);

#endif
