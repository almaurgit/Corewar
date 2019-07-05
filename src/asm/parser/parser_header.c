/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_header.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:10:01 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/04 12:06:24 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "lftstring.h"

/*
**	Check if name or comment already exists, and set it
*/

static int	valid_name_comment(t_data *data, char **line, char type)
{
	data->wait_quotes_state = -1;
	data->index_name_comment = 0;
	if (type == 1)
	{
		if (data->found_name == 1)
		{
			ft_strdel(line);
			return (error(data, DUPLICATE_NAME_ERROR));
		}
		data->found_name = 1;
	}
	else
	{
		if (data->found_comment == 1)
		{
			ft_strdel(line);
			return (error(data, DUPLICATE_COM_ERROR));
		}
		data->found_comment = 1;
	}
	return (1);
}

/*
**	Check if name or comment is not too long
*/

static int	check_buffer_length(t_data *data, char **line, int len, char type)
{
	if (type == 1 && len > PROG_NAME_LENGTH)
	{
		ft_strdel(line);
		return (error(data, NAME_TOO_LONG_ERROR));
	}
	else if (type == 0 && len > COMMENT_LENGTH)
	{
		ft_strdel(line);
		return (error(data, COMMENT_TOO_LONG_ERROR));
	}
	return (1);
}

/*
**	If the name or the comment is multi-lined, append the next line to the
**	name/comment
*/

int			append_name_comment(t_data *data, char **line, char type)
{
	int		i;
	char	*buffer;

	i = 0;
	buffer = type == 1 ? data->name : data->comment;
	while ((*line)[i] && (*line)[i] != '"')
	{
		buffer[data->index_name_comment++] = (*line)[i++];
		check_buffer_length(data, line, data->index_name_comment, type);
	}
	if ((*line)[i] == '"' && (*line)[i + 1])
		return (error_parse_line(data, BAD_TOKEN_AFTER_NAME, line));
	if ((*line)[i] != '"')
	{
		ft_strdel(line);
		buffer[data->index_name_comment++] = '\n';
		check_buffer_length(data, line, data->index_name_comment, type);
	}
	else
		valid_name_comment(data, line, type);
	return (1);
}

/*
**	If the name or the comment is one-lined, just put it in the buffer
*/

static void	handle_one_line(t_data *data, char **line, char *tmp, char type)
{
	int		len;

	len = ft_strlen(tmp + 1) - 1;
	check_buffer_length(data, line, len, type);
	if (type == 1)
		ft_strncpy(data->name, tmp + 1, len);
	else
		ft_strncpy(data->comment, tmp + 1, len);
}

/*
**	Retrieve the line we sent in, remove quotes from it and
**	assign it to its variable (`comment` or `name` in data)
*/

int			retrieve_name_comment(t_data *data, char **line, char *raw_line)
{
	int		i;
	char	type;

	i = 1;
	type = ft_strnequ(*line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING));
	while (raw_line[i] && raw_line[i] != '"')
		i++;
	if (raw_line[i] == '\0')
	{
		data->wait_quotes_state = type;
		raw_line = try_malloc(data, ft_strdup(raw_line + 1), line);
		ft_strdel(line);
		return (append_name_comment(data, &raw_line, type));
	}
	else if (raw_line[i + 1] && raw_line[i + 1])
		return (error_parse_line(data, BAD_SYNTAX_ERROR, line));
	handle_one_line(data, line, raw_line, type);
	return (valid_name_comment(data, line, type));
}
