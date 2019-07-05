/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 00:38:35 by efouille          #+#    #+#             */
/*   Updated: 2019/03/25 14:51:57 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TYPES_H
# define LIBFT_TYPES_H

/*
** size_t
*/
# include <string.h>

/*
** (u)intmax_t and (u)intXX_t
*/
# include <stdint.h>

# ifndef NULL
#  define NULL ((void*)0)
# endif

/*
** shorter version for integer types
*/
typedef uintmax_t			t_umax;
typedef intmax_t			t_imax;
typedef uint8_t				t_u8;
typedef int8_t				t_i8;
typedef uint16_t			t_u16;
typedef int16_t				t_i16;
typedef uint32_t			t_u32;
typedef int32_t				t_i32;
typedef uint64_t			t_u64;
typedef int64_t				t_i64;
typedef unsigned char		t_uchar;
typedef unsigned short		t_ushort;
typedef unsigned int		t_uint;
typedef unsigned long		t_ul;
typedef unsigned long long	t_ull;

/*
** generic lists and stacks
*/
typedef	struct				s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}							t_list;
typedef	t_list				t_stack;

/*
** variable sizes matrixes
*/
typedef struct				s_matrix
{
	float			**m;
	int				w;
	int				h;
}							t_matrix;

/*
** faster string type
*/
typedef struct				s_str
{
	char			*str;
	size_t			len;
}							t_str;

/*
** bit fields for floating point numbers
*/
typedef struct				s_float
{
	t_uint	mantissa : 23;
	t_uint	exponent : 8;
	t_uint	sign : 1;
}							t_float;

typedef struct				s_double
{
	t_ul	mantissa : 52;
	t_ul	exponent : 11;
	t_ul	sign : 1;
}							t_double;

typedef struct				s_ldouble
{
	t_ul	mantissa : 64;
	t_ul	exponent : 15;
	t_ul	sign : 1;
	t_ul	junk : 16;
}							t_ldouble;

/*
** date type mainly for printf for now
*/
typedef struct				s_date
{
	t_u16	years;
	t_u8	months;
	t_u8	days;
	t_u8	hours;
	t_u8	minutes;
	t_u8	seconds;
}							t_date;

#endif
