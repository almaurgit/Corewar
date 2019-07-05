/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:12:54 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/05 21:26:20 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "lftstring.h"
#include "ft_get_next.h"
#include "ft_printf.h"
#include "lftctype.h"
#include <fcntl.h>
#include <unistd.h>

/*
**	Return the next non-comment and non-empty line
*/

static int		skip_comments(t_data *data, int fd, char **line)
{
	int		gnl_result;

	while ((gnl_result = get_next_line(fd, line)) > 0)
	{
		++data->parse_line_number;
		if (data->wait_quotes_state != -1)
			break ;
		trim_and_remove_comments(data, line);
		if (!line || !*line || *line[0] == '\0')
			ft_strdel(line);
		else
			break ;
	}
	return (gnl_result);
}

/*
**	Trim a string and remove comments
**	Example : '  st r1, r2, r3   #comment' will output 'st r1, r2, r3'
*/

int				trim_and_remove_comments(t_data *data, char **str)
{
	char	*result;
	int		i;

	if (!str || !*str || ft_strlen(*str) == 0)
		return (0);
	i = -1;
	while ((*str)[++i])
	{
		if ((*str)[i] == COMMENT_CHAR && !ft_strnstr(*str, NAME_CMD_STRING, i)
			&& !ft_strnstr(*str, COMMENT_CMD_STRING, i))
		{
			if (!(*str = ft_strsub_free(*str, 0, i)))
				return (error(data, MALLOC_ERROR));
			break ;
		}
	}
	if (!(result = ft_strtrim(*str)))
	{
		ft_strdel(str);
		return (error(data, STRING_TRIM_ERROR));
	}
	ft_strdel(str);
	*str = result;
	return (1);
}

/*
**	This function returns the string after the quote and check if there is
**	errors before the quotes, or if a quote is missing
**	Example : '.nameTEST "hello"' will throw an error
**	Example 2 : '.name output"' will throw an other error
**	Example 3 : '.name "good"' will returns 'good"'
*/

static char		*get_string_in_quote(t_data *data, char **line, int type)
{
	char		*result;
	int			i;

	if (!(result = ft_strchr(*line, '"')))
	{
		ft_strdel(line);
		error_parse_line(data, MISSING_QUOTE_ERROR, line);
		return (NULL);
	}
	i = type == 1 ? ft_strlen(NAME_CMD_STRING) : ft_strlen(COMMENT_CMD_STRING);
	while ((*line)[i] && (*line)[i] != '"')
	{
		if (!ft_isspace((*line)[i++]))
		{
			ft_strdel(line);
			error_parse_line(data, BAD_NAME_COMMENT, line);
			return (NULL);
		}
	}
	return (result);
}

/*
**	Parse the line and retrieve his arguments
*/

static int		parse_line(t_data *data, char **line)
{
	char		*label_name;
	char		*string_in_quote;

	if (ft_strnequ(*line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING))
		|| ft_strnequ(*line, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
	{
		string_in_quote = get_string_in_quote(data, line, ft_strnequ(*line,
					NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)));
		return (retrieve_name_comment(data, line, string_in_quote));
	}
	if (data->wait_quotes_state != -1)
		return (append_name_comment(data, line, data->wait_quotes_state));
	if ((label_name = parse_next_label(data, line)))
		create_label(data, label_name);
	parse_next_instru(data, line);
	return (1);
}

/*
**	Parse the .s file
*/

int				parse(t_data *data, char debug_mode)
{
	int		fd;
	int		gnl_result;
	char	*line;

	line = NULL;
	if ((fd = open(data->input_file, O_RDONLY)) < 0)
		return (error(data, FILE_ERROR));
	while ((gnl_result = skip_comments(data, fd, &line)) > 0)
	{
		if (debug_mode)
		{
			ft_printf("Parsing line #%d", data->parse_line_number);
			ft_printf(" '%s'..\n", line);
		}
		parse_line(data, &line);
		ft_strdel(&line);
	}
	if (data->wait_quotes_state != -1)
		return (error(data, MISSING_QUOTE_ERROR));
	if (gnl_result < 0)
		return (error(data, READ_ERROR));
	close(fd);
	return (1);
}
