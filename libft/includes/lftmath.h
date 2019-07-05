/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lftmath.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 23:23:38 by efouille          #+#    #+#             */
/*   Updated: 2019/04/18 01:51:17 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFTMATH_H
# define LFTMATH_H

# include "libft_types.h"

t_imax		ft_2_complement(t_imax n);
t_umax		ft_abs(t_imax n);
int			ft_getbit(t_imax n, int index);
int			ft_getfbit(float n, int index);
int			ft_getfexponent(float n);
int			ft_getfmantissa(float n);
int			ft_getfmantissa_dec(float n);
int			ft_getfsign(float n);
int			ft_log(t_umax n, int b);
t_matrix	*ft_matadd(t_matrix *a, t_matrix *b);
void		ft_matdel(t_matrix **a);
void		ft_matmult(t_matrix *a, float k);
t_matrix	*ft_matnew(int w, int h);
t_matrix	*ft_matprod(t_matrix *a, t_matrix *b);
int			ft_max(int a, int b);
int			ft_min(int a, int b);
int			ft_pow(int n, int p);
void		ft_setbit(t_imax *n, int index);
int			ft_sqrt(int n);
void		ft_swapbytes(t_u8 *bytes, t_uint n);
void		ft_unsetbit(t_imax *n, int index);

#endif
