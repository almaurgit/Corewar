/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:00:43 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/05 22:10:31 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "lftstring.h"
#include "ft_printf.h"
#include <unistd.h>

/*
**	Init our main struct t_data
**	(setting all pointers to NULL, init operations, etc)
*/

static void		init_struct(t_data *data, char *file)
{
	ft_bzero(data, sizeof(t_data));
	data->wait_quotes_state = -1;
	init_ops(data);
	data->input_file = file;
}

/*
**	Check if we have enough informations and if all the instructions are valid
*/

static int		checker(t_data *data)
{
	if (data->found_name == 0)
		return (error(data, NO_NAME_ERROR));
	else if (data->found_comment == 0)
		return (error(data, NO_COMMENT_ERROR));
	else if (data->instrus == NULL && data->labels == NULL)
		return (error(data, NO_INSTRUS_ERROR));
	check_instrus_validity(data);
	return (1);
}

/*
**	Check if we have enough informations and if all the instructions are valid
*/

static void		handle_champion(t_data *data, char *file, char debug, char path)
{
	init_struct(data, file);
	parse(data, debug);
	checker(data);
	write_all(data, debug);
	if (path)
		ft_printf("%s\n", data->out_file);
	else
		ft_printf("[ASM] Writing output program to %s\n", data->out_file);
	free_all(data);
}

int				main(int ac, char **av)
{
	t_data		data;
	int			i;
	char		debug_mode;
	char		path_mode;

	if (ac < 2 || !read_arguments(ac, av, &debug_mode, &path_mode))
	{
		ft_dprintf(STDERR_FILENO, USAGE_ERROR "\n");
		return (EXIT_FAILURE);
	}
	i = 0;
	while (++i < ac)
	{
		if (is_debug_arg(av[i]) || is_path_arg(av[i]))
			continue ;
		handle_champion(&data, av[i], debug_mode, path_mode);
	}
	return (0);
}
