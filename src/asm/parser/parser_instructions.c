/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:07:50 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/08 14:44:38 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "lftstring.h"
#include "lftctype.h"
#include <stdlib.h>

/*
**	Read the instruction and remove it from the line
*/

static t_op	*pop_instru(t_data *data, char **line)
{
	t_op	*op;
	char	*word;
	int		i;

	i = -1;
	word = NULL;
	while ((*line)[++i])
		if (ft_isspace((*line)[i]) || (*line)[i + 1] == '\0')
		{
			word = try_malloc(data, ft_strsub(*line, 0, i
						+ ((*line)[i + 1] == '\0')), line);
			*line = try_malloc(data, ft_strsub_free(*line, i + ((*line)[i + 1]
							== '\0'), ft_strlen(*line) - i), &word);
			trim_and_remove_comments(data, line);
			op = get_op_by_name(data, word);
			ft_strdel(&word);
			return (op);
		}
	if (i != 0)
		error_parse_line(data, BAD_CHARACTER_ERROR, line);
	return (NULL);
}

/*
**	Create a buffer in order to remove spaces in the arguments
*/

static char	*create_buffer(t_data *data, char **str)
{
	char	*result;
	int		i;
	int		final_length;

	i = 0;
	final_length = 0;
	while ((*str)[i])
		if (!ft_isspace((*str)[i++]))
			final_length++;
	result = try_malloc(data, (char *)malloc(sizeof(char)
				* (final_length + 1)), str);
	result[final_length] = '\0';
	return (result);
}

/*
**	If the condition returns true, there is a problem with parsing:
**  we exit the program
*/

static int	check_args_error(t_data *data, char **str, int condition)
{
	if (condition)
		return (error_parse_line(data, BAD_SEPARATOR_ERROR, str));
	return (1);
}

/*
**	Removes all spaces from a string (only if the space is glued to a comma)
**	Example : 'st r1  ,  %17,   5' will output 'st r1,%17,5'
*/

static void	remove_glued_spaces(t_data *data, char **s, char *result)
{
	int		i;
	int		j;
	char	found_comma;

	i = -1;
	j = 0;
	found_comma = 1;
	while (*(*s + ++i))
	{
		check_args_error(data, s, !found_comma && ft_isspace((*s)[i])
			&& !ft_isspace((*s)[i + 1]) && (*s)[i + 1] != SEPARATOR_CHAR);
		if ((*s)[i] == SEPARATOR_CHAR)
		{
			check_args_error(data, s, found_comma == 1);
			found_comma = 1;
		}
		else if (!ft_isspace((*s)[i]))
			found_comma = 0;
		if (!ft_isspace((*s)[i]))
			result[j++] = (*s)[i];
	}
	check_args_error(data, s, found_comma == 1);
	ft_strdel(s);
	*s = result;
}

/*
**	Handle instruction and arguments, and save it
*/

int			parse_next_instru(t_data *data, char **line)
{
	t_op		*op;
	char		**args;

	if (ft_strlen(*line) == 0)
		return (0);
	if ((op = pop_instru(data, line)) == NULL)
		return (error_parse_line(data, BAD_INSTRUCTION_ERROR, line));
	remove_glued_spaces(data, line, create_buffer(data, line));
	if (!(args = ft_strsplit(*line, SEPARATOR_CHAR)))
	{
		ft_strdel(line);
		return (error(data, MALLOC_ERROR));
	}
	if (ft_tablen(args) != op->nb_params)
	{
		free_array(args);
		return (error_parse_line(data, BAD_NUMBER_ARGS_ERROR, line));
	}
	return (create_instru(data, op, args));
}
