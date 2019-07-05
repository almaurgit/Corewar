/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 05:07:39 by efouille          #+#    #+#             */
/*   Updated: 2019/05/23 04:06:28 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_types.h"
#include "lftlib.h"
#include "lftmath.h"
#include "lftstring.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static t_corfile	*corfile_from_bytes(t_header header, t_u8 *program)
{
	t_corfile	*cf;

	if (!(cf = (t_corfile*)malloc(sizeof(t_corfile))))
		return (NULL);
	cf->header = header;
	cf->program = program;
	return (cf);
}

static t_header		buf_to_header(t_u8 *buf)
{
	t_header	header;

	header.magic = *((int*)buf);
	ft_swapbytes((t_u8*)&header.magic, sizeof(int));
	buf += (void*)&(header.prog_name) - (void*)&(header.magic);
	ft_memcpy(&(header.prog_name), buf, sizeof(header.prog_name));
	buf += (void*)&(header.prog_size) - (void*)&(header.prog_name);
	header.prog_size = *((int*)buf);
	ft_swapbytes((t_u8*)&header.prog_size, sizeof(int));
	buf += (void*)&(header.comment) - (void*)&(header.prog_size);
	ft_memcpy(&(header.comment), buf, sizeof(header.comment));
	return (header);
}

static int			close_return(int fd, int ret)
{
	close(fd);
	return (ret);
}

int					read_cor(char *path, t_corfile **cf)
{
	int			fd;
	int			read_bytes;
	t_header	header;
	t_u8		buf[sizeof(t_header)];
	t_u8		*program;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (cw_open_error);
	if ((read_bytes = read(fd, buf, sizeof(t_header))) != sizeof(t_header))
		return (close_return(fd, cw_header_error));
	header = buf_to_header(buf);
	if (header.magic != COREWAR_EXEC_MAGIC)
		return (close_return(fd, cw_magic_error));
	if (header.prog_size > CHAMP_MAX_SIZE)
		return (close_return(fd, cw_size_error));
	if (!(program = (t_u8*)ft_memalloc(header.prog_size * sizeof(t_u8))))
		return (close_return(fd, cw_malloc_error));
	read_bytes = read(fd, program, header.prog_size);
	if (!(*cf = corfile_from_bytes(header, program)))
		return (close_return(fd, cw_malloc_error));
	return (close_return(fd, read_bytes));
}
