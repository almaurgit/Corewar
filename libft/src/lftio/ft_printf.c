/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 01:18:12 by efouille          #+#    #+#             */
/*   Updated: 2019/03/25 15:25:40 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "lftstring.h"
#include <unistd.h>

int	ft_vprintf(const char *format, va_list vl)
{
	int		size;
	char	*str;

	str = NULL;
	if ((size = ft_vasprintf(&str, format, vl)) > -1)
		write(1, str, size >= 0 ? size : (int)ft_strlen(str));
	free(str);
	return (size);
}

int	ft_printf(const char *format, ...)
{
	int		size;
	va_list	vl;

	va_start(vl, format);
	size = ft_vprintf(format, vl);
	va_end(vl);
	return (size);
}
