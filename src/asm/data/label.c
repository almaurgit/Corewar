/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:14:33 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/04 18:48:54 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "lftstring.h"
#include <stdlib.h>

/*
**	Add a label to our binary tree
*/

static void	add_label_to_tree(t_label **tree, t_label *label)
{
	int		cmp;

	if (*tree == NULL)
		*tree = label;
	else
	{
		cmp = ft_strcmp((const char *)(*tree)->name, (const char *)label->name);
		if (cmp > 0)
			add_label_to_tree(&(*tree)->right, label);
		else
			add_label_to_tree(&(*tree)->left, label);
	}
}

/*
**	Loop over our binary tree and search for label 'name'
*/

t_label		*get_label_by_name(t_data *data, char *name)
{
	t_label	*label;
	int		cmp;

	label = data->labels;
	while (label)
	{
		cmp = ft_strcmp((const char *)label->name, (const char *)name);
		if (cmp == 0)
			return (label);
		else
		{
			if (cmp > 0)
				label = label->right;
			else
				label = label->left;
		}
	}
	return (NULL);
}

/*
**	Create a label
*/

int			create_label(t_data *data, char *name)
{
	t_label			*result;
	t_instru		*tmp_instru;

	if (!(result = (t_label *)malloc(sizeof(t_label))))
	{
		free(name);
		return (error(data, MALLOC_ERROR));
	}
	tmp_instru = data->instrus;
	while (tmp_instru && tmp_instru->next)
		tmp_instru = tmp_instru->next;
	result->name = name;
	result->pc = get_pc_after(data, tmp_instru);
	result->left = NULL;
	result->right = NULL;
	add_label_to_tree(&data->labels, result);
	return (1);
}
