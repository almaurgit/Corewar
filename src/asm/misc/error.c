/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 10:53:22 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/12 13:29:13 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "ft_printf.h"
#include "lftstring.h"
#include <unistd.h>

/*
**	Exit function : free all pointers dynamically allocated, write a custom
**	message with the instruction and the args, and exit the program
*/

int			error_args(t_data *data, t_instru *instru, char *error)
{
	int		i;

	ft_dprintf(STDERR_FILENO, "[ERROR] File %s : ", data->input_file);
	ft_dprintf(STDERR_FILENO, "At instruction '%s ", instru->op->name);
	i = -1;
	while (++i < instru->op->nb_params)
		ft_dprintf(STDERR_FILENO, "%s%s", i == 0 ? "" : ", ", instru->args[i]);
	ft_dprintf(STDERR_FILENO, "' -> %s\n", error);
	free_all(data);
	exit(EXIT_FAILURE);
	return (0);
}

/*
**	Exit function : free all pointers dynamically allocated, write the current
**	line number, the line, and a custom message, and exit the program
*/

int			error_parse_line(t_data *data, char *error, char **line)
{
	int		i;

	i = data->parse_line_number;
	ft_dprintf(STDERR_FILENO, "[ERROR] File %s : ", data->input_file);
	if (!line || !*line || ft_strlen(*line) == 0)
		ft_dprintf(STDERR_FILENO, PARSE_ERROR, i);
	else
		ft_dprintf(STDERR_FILENO, PARSE_ERROR_LINE, i, *line);
	ft_strdel(line);
	ft_dprintf(STDERR_FILENO, " -> %s\n", error);
	free_all(data);
	exit(EXIT_FAILURE);
	return (0);
}

/*
**	Exit function : print a custom error message, free all pointers
**	dynamically allocated and exit the program
*/

int			error(t_data *data, char *error_msg)
{
	ft_dprintf(STDERR_FILENO, "[ERROR] File %s : ", data->input_file);
	ft_dprintf(STDERR_FILENO, "%s\n", error_msg);
	free_all(data);
	exit(EXIT_FAILURE);
	return (0);
}
