/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 01:27:59 by efouille          #+#    #+#             */
/*   Updated: 2019/01/07 03:24:04 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>

int	ft_vasprintf(char **str, const char *format, va_list vl);
int	ft_asprintf(char **str, const char *format, ...);

int	ft_vdprintf(int fd, const char *format, va_list vl);
int	ft_dprintf(int fd, const char *format, ...);

int	ft_vprintf(const char *format, va_list vl);
int	ft_printf(const char *format, ...);

int	ft_vsprintf(char *str, const char *format, va_list vl);
int	ft_sprintf(char *str, const char *format, ...);
int	ft_vsnprintf(char *str, size_t size, const char *format, va_list vl);
int	ft_snprintf(char *str, size_t size, const char *format, ...);

#endif
