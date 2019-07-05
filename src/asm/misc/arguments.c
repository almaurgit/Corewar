/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:55:24 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/05 21:31:11 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "lftstring.h"
#include "ft_printf.h"

/*
**	Write all the found labels
*/

static void		write_debug_labels(t_label *label)
{
	if (label != NULL)
	{
		ft_printf("'%s'\n", label->name);
		write_debug_labels(label->left);
		write_debug_labels(label->right);
	}
}

/*
**	Write the name, the comment, and all the instructions found
*/

void			write_debug(t_data *data)
{
	t_instru	*instru;
	int			i;

	instru = data->instrus;
	ft_printf("\n----- Header -----\n");
	ft_printf("Name : '%s'\nComment : '%s'\n\n", data->name, data->comment);
	ft_printf("----- Instructions -----\n");
	while (instru)
	{
		i = -1;
		ft_printf("%5s\t args={", instru->op->name);
		while (++i < instru->op->nb_params)
		{
			if (i != 0)
				ft_printf(", ");
			ft_printf("%s", instru->args[i]);
		}
		ft_printf("}\n");
		instru = instru->next;
	}
	ft_printf("\n----- Labels -----\n");
	write_debug_labels(data->labels);
	ft_printf("\nStarting write of .cor file..\n\n");
}

/*
**	Return true if the given arg is the debug mode format
*/

char			is_debug_arg(char *arg)
{
	return (ft_strequ(arg, DEBUG_ARG_1) || ft_strequ(arg, DEBUG_ARG_2));
}

/*
**	Return true if the given arg is the print-path mode format
*/

char			is_path_arg(char *arg)
{
	return (ft_strequ(arg, PATH_ARG_1) || ft_strequ(arg, PATH_ARG_2));
}

/*
**	Check if there is a debug or a print-path arg
**	Return true if there is at least one champion, false otherwise
*/

char			read_arguments(int ac, char **av, char *debug, char *path)
{
	int			i;
	char		found_champion;

	*debug = 0;
	*path = 0;
	i = 1;
	found_champion = 0;
	while (i < ac)
	{
		if (is_debug_arg(av[i]))
			*debug = 1;
		else if (is_path_arg(av[i]))
			*path = 1;
		else
			found_champion = 1;
		i++;
	}
	return (found_champion);
}
