/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchartostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:54:41 by efouille          #+#    #+#             */
/*   Updated: 2019/03/25 15:28:26 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_wchartostr_11b(wchar_t c)
{
	char	*ws;

	if (!(ws = (char*)malloc(3 * sizeof(char))))
		return (NULL);
	ws[2] = 0;
	ws[1] = 0x80 + (c & 0x3F);
	c = c >> 6;
	ws[0] = 0xC0 + (c & 0x1F);
	return (ws);
}

static char	*ft_wchartostr_16b(wchar_t c)
{
	char	*ws;

	if (!(ws = (char*)malloc(4 * sizeof(char))))
		return (NULL);
	ws[3] = 0;
	ws[2] = 0x80 + (c & 0x3F);
	c = c >> 6;
	ws[1] = 0x80 + (c & 0x3F);
	c = c >> 6;
	ws[0] = 0xE0 + (c & 0xF);
	return (ws);
}

static char	*ft_wchartostr_21b(wchar_t c)
{
	char	*ws;

	if (!(ws = (char*)malloc(5 * sizeof(char))))
		return (NULL);
	ws[4] = 0;
	ws[3] = 0x80 + (c & 0x3F);
	c = c >> 6;
	ws[2] = 0x80 + (c & 0x3F);
	c = c >> 6;
	ws[1] = 0x80 + (c & 0x3F);
	c = c >> 6;
	ws[0] = 0xF0 + (c & 0x07);
	return (ws);
}

char		*ft_wchartostr(wchar_t c)
{
	char	*str;

	str = NULL;
	if (c <= 0x7f)
	{
		if (!(str = (char*)malloc(2 * sizeof(char))))
			return (NULL);
		str[0] = (char)c;
		str[1] = 0;
	}
	else if (c <= 0x7ff)
		str = ft_wchartostr_11b(c);
	else if (c <= 0xffff)
		str = ft_wchartostr_16b(c);
	else if (c <= 0x10ffff)
		str = ft_wchartostr_21b(c);
	else
		str = NULL;
	return (str);
}
