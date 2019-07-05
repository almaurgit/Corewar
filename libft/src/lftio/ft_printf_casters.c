/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 04:24:33 by efouille          #+#    #+#             */
/*   Updated: 2019/01/15 16:12:21 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include <sys/types.h>

void	cast_uint(t_pfenv *env, t_umax *n)
{
	if (env->cur_fmt->modifiers & M_HH)
		*n = (t_uchar)(*n);
	else if (env->cur_fmt->modifiers & M_H)
		*n = (t_ushort)(*n);
	else if (env->cur_fmt->modifiers & M_LL)
		*n = (t_ull)(*n);
	else if (env->cur_fmt->modifiers & M_L)
		*n = (t_ul)(*n);
	else if (env->cur_fmt->modifiers & M_J)
		*n = (t_umax)(*n);
	else if (env->cur_fmt->modifiers & M_Z)
		*n = (size_t)(*n);
	else
		*n = (t_uint)(*n);
}

void	cast_int(t_pfenv *env, t_imax *n)
{
	if (env->cur_fmt->modifiers & M_HH)
		*n = (char)(*n);
	else if (env->cur_fmt->modifiers & M_H)
		*n = (short)(*n);
	else if (env->cur_fmt->modifiers & M_LL)
		*n = (long long)(*n);
	else if (env->cur_fmt->modifiers & M_L)
		*n = (long)(*n);
	else if (env->cur_fmt->modifiers & M_J)
		*n = (t_imax)(*n);
	else if (env->cur_fmt->modifiers & M_Z)
		*n = (ssize_t)(*n);
	else
		*n = (int)(*n);
}
