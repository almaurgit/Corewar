/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:35:12 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/08 14:50:56 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "lftstring.h"
#include <stdlib.h>

/*
**	Free the labels
*/

static void	free_labels(t_label *label)
{
	if (label != NULL)
	{
		ft_strdel(&label->name);
		free_labels(label->left);
		free_labels(label->right);
		free(label);
	}
}

/*
**	Free the instructions
*/

static void	free_instructions(t_data *data)
{
	t_instru	*tmp;

	while (data->instrus)
	{
		tmp = data->instrus->next;
		free_array(data->instrus->args);
		free(data->instrus);
		data->instrus = tmp;
	}
}

/*
**	Free a double char array
*/

void		free_array(char **tab)
{
	int	i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i])
		{
			ft_strdel(&tab[i]);
			i++;
		}
		free(tab);
	}
}

/*
**	Free all the allocated pointers
*/

void		free_all(t_data *data)
{
	if (data)
	{
		if (data->out_file)
			ft_strdel(&data->out_file);
		free_labels(data->labels);
		free_instructions(data);
	}
}

/*
**	If string 'malloc' is NULL, free the 'to_free' char, and exit the program
*/

char		*try_malloc(t_data *data, char *malloc, char **to_free)
{
	if (!malloc)
	{
		ft_strdel(to_free);
		error(data, MALLOC_ERROR);
		return (NULL);
	}
	return (malloc);
}
