/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:43:08 by efouille          #+#    #+#             */
/*   Updated: 2019/01/16 00:58:27 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_vdprintf(int fd, const char *format, va_list vl)
{
	int		size;
	char	*str;

	str = NULL;
	if ((size = ft_vasprintf(&str, format, vl)) > -1)
		write(fd, str, size);
	free(str);
	return (size);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	int		size;
	char	*str;
	va_list	vl;

	str = NULL;
	va_start(vl, format);
	size = ft_vasprintf(&str, format, vl);
	write(fd, str, size);
	free(str);
	va_end(vl);
	return (size);
}
