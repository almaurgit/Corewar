/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:59:36 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/08 14:48:30 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "lftstring.h"
#include "lftmath.h"
#include "ft_printf.h"
#include "lftlib.h"
#include <unistd.h>
#include <fcntl.h>

/*
**	Return total size of the program
*/

static unsigned int	get_prog_size(t_data *data)
{
	unsigned int	total_size;
	t_instru		*instru;

	total_size = 0;
	instru = data->instrus;
	while (instru)
	{
		total_size += instru->size_instru;
		instru = instru->next;
	}
	return (total_size);
}

/*
**	Write the header in the .cor file (including prog name, comment, magic
**	number and the program size)
*/

static int			write_header(t_data *data, int fd)
{
	t_header	*header;

	if (!(header = (t_header *)ft_memalloc(sizeof(t_header))))
		return (error(data, MALLOC_ERROR));
	ft_bzero(header->prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(header->comment, COMMENT_LENGTH + 1);
	ft_strncpy(header->prog_name, data->name, PROG_NAME_LENGTH);
	ft_strncpy(header->comment, data->comment, COMMENT_LENGTH);
	header->magic = COREWAR_EXEC_MAGIC;
	ft_swapbytes((t_u8 *)&header->magic, 4);
	header->prog_size = get_prog_size(data);
	ft_swapbytes((t_u8 *)&header->prog_size, 4);
	write(fd, header, sizeof(t_header));
	free(header);
	return (1);
}

/*
**	Write the code of the instruction in the .cor file
*/

static void			write_arg_code(int fd, t_instru *instru)
{
	unsigned char	c;
	t_arg_code		*code;
	int				i;

	c = 0;
	code = (t_arg_code *)&c;
	i = 0;
	while (i < instru->op->nb_params)
	{
		if (i == 0)
			code->arg0 = get_arg_code(instru->args[i]);
		else if (i == 1)
			code->arg1 = get_arg_code(instru->args[i]);
		else if (i == 2)
			code->arg2 = get_arg_code(instru->args[i]);
		i++;
	}
	code->left = 0;
	write(fd, &c, 1);
}

/*
**	Write the opcode, the arg code, and the types of the arguments in the
**	.cor file
*/

static void			write_prog(t_data *data, int fd)
{
	t_instru	*instru;

	instru = data->instrus;
	while (instru)
	{
		write(fd, &instru->op->id, 1);
		if (instru->op->encoding_byte == 1)
			write_arg_code(fd, instru);
		write_args(data, fd, instru);
		instru = instru->next;
	}
}

/*
**	Create the .cor file and write the entirely binary code (header,
**	arguments, instructions..)
*/

int					write_all(t_data *data, char debug_mode)
{
	int		fd;
	int		i;
	char	*file_name;

	if (debug_mode == 1)
		write_debug(data);
	if (!(file_name = ft_strdup(data->input_file)))
		return (error(data, MALLOC_ERROR));
	i = ft_strlen(file_name);
	while (--i)
		if (file_name[i] == '.')
		{
			if (!(file_name = ft_strsub_free(file_name, 0, i)))
				return (error(data, MALLOC_ERROR));
			break ;
		}
	if (!(data->out_file = ft_strjoin_free(file_name, ".cor")))
		return (error(data, MALLOC_ERROR));
	if ((fd = open(data->out_file, O_WRONLY | O_TRUNC | O_CREAT, 0600)) < 0)
		return (error(data, WRITE_ERROR));
	write_header(data, fd);
	write_prog(data, fd);
	close(fd);
	return (1);
}
