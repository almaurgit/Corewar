/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instru.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:14:43 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/04 18:50:27 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "lftctype.h"
#include "lftlib.h"
#include <stdlib.h>

/*
**	Return the type of the arg (direct, indirect or register)
*/

t_arg_type			get_arg_type(char *arg)
{
	if (arg[0] == DIRECT_CHAR)
		return (T_DIR);
	if (arg[0] == REGISTER_CHAR)
		return (T_REG);
	return (T_IND);
}

/*
**	Return the size in bytes of a instruction and its arguments
*/

static unsigned int	get_instru_size(t_op *op, char **args)
{
	int				i;
	unsigned int	total_size;

	i = 0;
	total_size = 1;
	if (op->encoding_byte == 1)
		total_size++;
	while (i < op->nb_params)
	{
		if (args[i][0] == DIRECT_CHAR)
			total_size += (op->dir_size == 0 ? DIR_WRITE_SIZE : IND_WRITE_SIZE);
		else if (args[i][0] == REGISTER_CHAR)
			total_size += REG_WRITE_SIZE;
		else
			total_size += IND_WRITE_SIZE;
		i++;
	}
	return (total_size);
}

/*
**	Check if arg is valid
*/

static int			assert_arg_valid(t_data *data, t_instru *instru, char *arg)
{
	if (arg[0] == REGISTER_CHAR && (!ft_isnumber(arg + 1)
			|| ft_atoi(arg + 1) > REG_NUMBER || ft_atoi(arg + 1) <= 0))
		return (error_args(data, instru, BAD_REGISTER_ERROR));
	else if (arg[0] == LABEL_CHAR
		&& !get_label_by_name(data, arg + 1))
		return (error_args(data, instru, ARG_LABEL_NULL_ERROR));
	else if (arg[0] == DIRECT_CHAR && arg[1] == LABEL_CHAR
		&& !get_label_by_name(data, arg + 2))
		return (error_args(data, instru, ARG_LABEL_NULL_ERROR));
	else if (arg[0] == DIRECT_CHAR && arg[1] != LABEL_CHAR
		&& !ft_isnumber(arg + 1))
		return (error_args(data, instru, ARG_NOT_NUMBER_ERROR));
	else if (arg[0] != DIRECT_CHAR && arg[0] != LABEL_CHAR
		&& arg[0] != REGISTER_CHAR && !ft_isnumber(arg))
		return (error_args(data, instru, ARG_NOT_NUMBER_ERROR));
	return (1);
}

/*
**	Loop over all the arguments, and check if these ones are valid
*/

int					check_instrus_validity(t_data *data)
{
	int				i;
	char			**args;
	t_instru		*instru;
	t_arg_type		arg_type;

	instru = data->instrus;
	while (instru)
	{
		i = -1;
		args = instru->args;
		while (++i < instru->op->nb_params)
		{
			assert_arg_valid(data, instru, args[i]);
			arg_type = get_arg_type(args[i]);
			if ((arg_type & instru->op->params_type[i]) != arg_type)
				return (error_args(data, instru, BAD_TYPE_ERROR));
		}
		instru = instru->next;
	}
	return (1);
}

/*
**	Create an instruction, and add it to the linked list
*/

int					create_instru(t_data *data, t_op *op, char **args)
{
	t_instru	*result;
	t_instru	*tmp_instru;

	if (!(result = (t_instru *)malloc(sizeof(t_instru))))
	{
		free_array(args);
		return (error(data, MALLOC_ERROR));
	}
	result->op = op;
	result->args = args;
	result->size_instru = get_instru_size(op, args);
	result->next = NULL;
	if (data->instrus == NULL)
		data->instrus = result;
	else
	{
		tmp_instru = data->instrus;
		while (tmp_instru && tmp_instru->next)
			tmp_instru = tmp_instru->next;
		tmp_instru->next = result;
	}
	return (1);
}
