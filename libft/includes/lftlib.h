/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lftlib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 12:43:02 by efouille          #+#    #+#             */
/*   Updated: 2019/03/24 10:45:38 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFTLIB_H
# define LFTLIB_H

# include "libft_types.h"

int		ft_atoi(const char *str);
t_imax	ft_atoimax(const char *str);
t_umax	ft_atoumax(const char *str);
t_uint	ft_days_before_month(t_uint m, t_uint y);
char	*ft_dtoa(long double n, int p, int s);
char	*ft_itoa(long n);
char	*ft_itoa_base(t_imax n, const t_uint b, const int caps);
t_uint	ft_leap_years_between(t_uint a, t_uint b);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
void	*ft_realloc(void *ap, size_t size, size_t new_size);
char	*ft_utoa_base(t_umax n, const t_uint b, int caps, int s);
int		ft_xatoi(const char *str, char *digits);
int		ft_yearisleap(t_uint y);

#endif
