/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_const.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 01:27:59 by efouille          #+#    #+#             */
/*   Updated: 2019/01/14 21:27:37 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_CONST_H
# define FT_PRINTF_CONST_H

/*
** values for flags (2^index)
*/
# define F_NONE 0
# define F_HASH 1
# define F_ZERO 2
# define F_MINUS 4
# define F_PLUS 8
# define F_SPACE 16
# define F_QUOTE 32

/*
** indexes of flags
*/
# define I_HASH 0
# define I_ZERO 1
# define I_MINUS 2
# define I_PLUS 3
# define I_ESPACE 4
# define I_QUOTE 5

/*
** values for lengthes (2^index)
*/
# define M_H 1
# define M_HH 2
# define M_L 4
# define M_LL 8
# define M_LLL 16
# define M_J 32
# define M_Z 64

/*
** indexes of lengthes
*/
# define I_H 0
# define I_HH 1
# define I_L 2
# define I_LL 3
# define I_LLL 4
# define I_J 5
# define I_Z 6

/*
** known flags, widthes, precisions, lengthes and conversions
*/
# define FLAGS "#0-+ '"
# define WIDTH "*0123456789"
# define PRECISION "*.0123456789"
# define MODIFIERS "hlLjz"
# define CONVERSIONS "cspdiouxXfFbBn%CSDOU"

#endif
