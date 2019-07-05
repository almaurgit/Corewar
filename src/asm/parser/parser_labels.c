/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_labels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:07:28 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/04 14:43:54 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "lftctype.h"
#include "lftstring.h"

/*
**	If exists, pop the label and remove it from the line
*/

static char	*pop_label(t_data *data, char **line)
{
	char	*word;
	char	old_character;
	int		i;
	char	*tmp;

	old_character = 0;
	i = 0;
	word = NULL;
	while ((*line)[i])
	{
		if ((*line)[i] == LABEL_CHAR && old_character != DIRECT_CHAR
			&& !ft_isspace(old_character))
		{
			word = try_malloc(data, ft_strsub(*line, 0, i), line);
			tmp = ft_strsub_free(*line, i + 1, ft_strlen(*line) - i - 1);
			*line = try_malloc(data, tmp, &word);
			trim_and_remove_comments(data, line);
			return (word);
		}
		old_character = (*line)[i++];
	}
	return (NULL);
}

/*
**	If exists, pop the label from the line and save it
*/

char		*parse_next_label(t_data *data, char **line)
{
	char	*label_name;
	int		i;

	label_name = pop_label(data, line);
	if (label_name != NULL)
	{
		i = -1;
		while (label_name[++i])
			if (ft_strchr(LABEL_CHARS, label_name[i]) == NULL)
			{
				ft_strdel(&label_name);
				error_parse_line(data, BAD_LABEL_NAME_ERROR, line);
				return (NULL);
			}
		if (label_name && get_label_by_name(data, label_name) != NULL)
		{
			ft_strdel(&label_name);
			error_parse_line(data, DUPLICATE_LABEL_ERROR, line);
			return (NULL);
		}
	}
	return (label_name);
}
