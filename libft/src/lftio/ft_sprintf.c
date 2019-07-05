/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:42:30 by efouille          #+#    #+#             */
/*   Updated: 2019/03/25 15:26:05 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "lftmath.h"
#include "lftstring.h"

int	ft_vsprintf(char *str, const char *format, va_list vl)
{
	int		size;
	char	*src;

	src = NULL;
	if ((size = ft_vasprintf(&src, format, vl)) > -1)
		ft_memcpy(str, src, size);
	free(str);
	return (size);
}

int	ft_sprintf(char *str, const char *format, ...)
{
	int		size;
	va_list	vl;

	va_start(vl, format);
	size = ft_vsprintf(str, format, vl);
	va_end(vl);
	return (size);
}

int	ft_vsnprintf(char *str, size_t size, const char *format, va_list vl)
{
	int		computed_size;
	int		real_size;
	char	*src;

	src = NULL;
	computed_size = ft_vasprintf(&src, format, vl);
	real_size = ft_min(computed_size, size - 1);
	real_size = real_size < 0 ? 0 : real_size;
	ft_memcpy(str, src, real_size);
	if ((size_t)computed_size > size && size > 0)
		str[size] = '\0';
	free(str);
	return (computed_size);
}

int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	int		computed_size;
	va_list	vl;

	va_start(vl, format);
	computed_size = ft_vsnprintf(str, size, format, vl);
	va_end(vl);
	return (computed_size);
}
