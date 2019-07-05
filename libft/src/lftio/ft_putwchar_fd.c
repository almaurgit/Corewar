/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 00:49:09 by efouille          #+#    #+#             */
/*   Updated: 2019/03/23 12:38:03 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lftio.h"
#include <unistd.h>
#include <wchar.h>

static void	ft_putchr_11b(wchar_t c, int fd)
{
	char	c1;
	char	c2;

	c2 = 0x80 + (c & 0x3F);
	c = c >> 6;
	c1 = 0xC0 + (c & 0x1F);
	write(1, &c1, fd);
	write(1, &c2, fd);
}

static void	ft_putchr_15b(wchar_t c, int fd)
{
	char	c1;
	char	c2;
	char	c3;

	c3 = 0x80 + (c & 0x3F);
	c = c >> 6;
	c2 = 0x80 + (c & 0x3F);
	c = c >> 6;
	c1 = 0xE0 + (c & 0xF);
	write(1, &c1, fd);
	write(1, &c2, fd);
	write(1, &c3, fd);
}

static void	ft_putchr_19b(wchar_t c, int fd)
{
	char	c1;
	char	c2;
	char	c3;
	char	c4;

	c4 = 0x80 + (c & 0x3F);
	c = c >> 6;
	c3 = 0x80 + (c & 0x3F);
	c = c >> 6;
	c2 = 0x80 + (c & 0x3F);
	c = c >> 6;
	c1 = 0xF0 + (c & 0x07);
	write(1, &c1, fd);
	write(1, &c2, fd);
	write(1, &c3, fd);
	write(1, &c4, fd);
}

static void	ft_putchr_23b(wchar_t c, int fd)
{
	char	c1;
	char	c2;
	char	c3;
	char	c4;
	char	c5;

	c5 = 0x80 + (c & 0x3F);
	c = c >> 6;
	c4 = 0x80 + (c & 0x3F);
	c = c >> 6;
	c3 = 0x80 + (c & 0x3F);
	c = c >> 6;
	c2 = 0x80 + (c & 0x3F);
	c = c >> 6;
	c1 = 0xF8 + (c & 0x03);
	write(1, &c1, fd);
	write(1, &c2, fd);
	write(1, &c3, fd);
	write(1, &c4, fd);
	write(1, &c5, fd);
}

void		ft_putwchar_fd(wchar_t c, int fd)
{
	if (c < 0x80)
		ft_putchar_fd(c, fd);
	else if (c < 0x800)
		ft_putchr_11b(c, fd);
	else if (c < 0x8000)
		ft_putchr_15b(c, fd);
	else if (c < 0x80000)
		ft_putchr_19b(c, fd);
	else if (c < 0x800000)
		ft_putchr_23b(c, fd);
}
