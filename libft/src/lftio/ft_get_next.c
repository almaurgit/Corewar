/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 03:09:50 by efouille          #+#    #+#             */
/*   Updated: 2019/03/23 23:39:52 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next.h"
#include "lftlib.h"
#include "lftstring.h"
#include <unistd.h>

static void	ft_copy_rest(char buf[2][BUFF_SIZE], int index)
{
	int	k;

	k = index + 1;
	while (k < BUFF_SIZE)
	{
		buf[0][k - index - 1] = buf[1][k];
		k++;
	}
	k = k - index - 1;
	while (k < BUFF_SIZE)
		buf[0][k++] = '\0';
}

static int	ft_add_to_line(t_gnlfile f, char buf[2][BUFF_SIZE], int s, char c)
{
	int	k;
	int	l;
	int	ret;

	k = 0;
	if (*(f.line))
		while ((*(f.line))[k])
			k++;
	ret = 0;
	if (ft_nindex_of(buf[1], c, BUFF_SIZE) > -1 && (ret = 1))
	{
		ft_copy_rest(buf, ft_nindex_of(buf[1], c, BUFF_SIZE));
		s = ft_nindex_of(buf[1], c, BUFF_SIZE);
	}
	if (s >= 0)
		*(f.line) = ft_realloc(*(f.line), k, k + s + 1);
	l = 0;
	while (l < s)
	{
		(*(f.line))[k + l] = buf[1][l];
		l++;
	}
	if (*(f.line))
		(*(f.line))[k + l] = '\0';
	return (ret);
}

static void	ft_gnl_read(t_gnlfile f, char sep, char buf[2][BUFF_SIZE], int *rb)
{
	int	ret;

	while (1)
	{
		ft_memset(buf[1], 0, BUFF_SIZE);
		if (buf[0] && buf[0][0])
		{
			ft_memcpy(buf[1], buf[0], BUFF_SIZE);
			ft_memset(buf[0], 0, BUFF_SIZE);
			*rb = BUFF_SIZE;
		}
		else
			*rb = read(f.fd, buf[1], BUFF_SIZE);
		if (buf[1][0] == '\0')
			ret = 1;
		else
			ret = ft_add_to_line(f, buf, *rb, sep);
		if (ret || *rb <= 0)
			break ;
	}
}

int			get_next(const int fd, char **line, char sep)
{
	t_gnlfile	file;
	static char	buf[2][BUFF_SIZE];
	int			read_b;
	int			ret;

	if (fd < 0 || fd > 4096 || !line)
		return (fail);
	file.fd = fd;
	file.line = line;
	*(file.line) = NULL;
	ft_gnl_read(file, sep, buf, &read_b);
	if (!(*line) || (read_b == 0 && *line && (*line)[0] == '\0'))
		ret = done;
	else
		ret = (read_b == -1 ? fail : ok);
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	return (get_next(fd, line, '\n'));
}
