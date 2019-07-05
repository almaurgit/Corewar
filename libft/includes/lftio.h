/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lftio.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 08:54:31 by efouille          #+#    #+#             */
/*   Updated: 2019/03/30 08:47:20 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFTIO_H
# define LFTIO_H

# include "libft_types.h"
# include <wchar.h>

void		ft_putchar_fd(char c, int fd);
void		ft_putchar(char c);
void		ft_putstr_fd(const char *s, int fd);
void		ft_putstr(const char *s);
void		ft_putendl_fd(const char *s, int fd);
void		ft_putendl(const char *s);
void		ft_putwchar_fd(wchar_t c, int fd);
void		ft_putwchar(wchar_t c);
void		ft_putwstr_fd(wchar_t *s, int fd);
void		ft_putwstr(wchar_t *s);
void		ft_putnbr_fd(t_imax n, int fd);
void		ft_putnbr(t_imax n);
void		ft_putunbr_fd(t_umax n, int fd);
void		ft_putunbr(t_umax n);
void		ft_puttstr(t_str *s);

#endif
