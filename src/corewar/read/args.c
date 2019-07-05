/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:11:22 by efouille          #+#    #+#             */
/*   Updated: 2019/06/04 18:46:15 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "lftctype.h"
#include "lftlib.h"
#include "lftstring.h"
#include "ft_printf.h"
#include "libft_const.h"
#include <stdlib.h>

static int	add_flag_ter(t_corewar *c, int ac, char **av, int i)
{
	char	*arg;

	arg = av[i];
	if (!ft_strcmp("-n", arg) || !ft_strcmp("--number", arg))
	{
		if (i + 1 < ac && ft_isnumber(av[i + 1]))
		{
			c->number_next_player = ft_atoi(av[i + 1]);
			c->flagnumber = 1;
			return (1);
		}
	}
	else if (!ft_strcmp("-t", arg) || !ft_strcmp("--tui", arg))
	{
		c->tui = 1;
		c->tui_pause = 1;
	}
	return (0);
}

static int	add_flag_bis(t_corewar *c, int ac, char **av, int i)
{
	char	*arg;

	arg = av[i];
	if (!ft_strcmp("-d", arg) || !ft_strcmp("--dump", arg))
	{
		if (i + 1 < ac)
			c->dump = ft_atoi(av[i + 1]);
		return (1);
	}
	else if (!ft_strcmp("-e", arg) || !ft_strcmp("--edump", arg))
	{
		if (i + 2 < ac)
		{
			c->dump = ft_atoi(av[i + 1]);
			c->dump_size = ft_atoi(av[i + 2]);
		}
		return (2);
	}
	else if (!ft_strcmp("-a", arg) || !ft_strcmp("--aff", arg))
	{
		c->show_aff = 1;
	}
	else
		return (add_flag_ter(c, ac, av, i));
	return (0);
}

static int	add_flag(t_corewar *c, int ac, char **av, int i)
{
	char	*arg;
	int		valid_v;

	arg = av[i];
	if (!ft_strcmp("-v", arg) || !ft_strcmp("--verbose", arg))
	{
		valid_v = i + 1 < ac && ft_isnumber(av[i + 1]) && av[i + 1][0] != '-';
		valid_v = valid_v && ft_strlen(av[i + 1]) <= 2;
		if (valid_v)
		{
			c->verbose = ft_atoi(av[i + 1]);
			if (c->verbose > V_INIT)
				c->verbose = V_ALL;
			return (1);
		}
		else
			c->verbose = V_ALL;
	}
	else
		return (add_flag_bis(c, ac, av, i));
	return (0);
}

static int	read_arg(t_corewar *c, char *arg)
{
	int			size;
	t_corfile	*cf;
	int			ret;

	size = read_cor(arg, &cf);
	if (size < 0)
		error(size, arg);
	else
	{
		if (c->verbose & V_INIT)
			ft_dprintf(2, "%s[ OK ]%s : read %s\n", SH_GREEN, SH_DEFAULT, arg);
		if ((ret = add_player(c, cf)))
			return (ret);
		if (c->verbose & V_INIT)
		{
			ft_printf("player %s ", c->players[c->nplayers - 1]->name);
			ft_printf("(%d)\n", c->players[c->nplayers - 1]->number);
		}
	}
	return (0);
}

int			read_args(t_corewar *c, int ac, char **av)
{
	int	i;
	int	ret;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
		{
			if ((ret = add_flag(c, ac, av, i)) == 2)
				i += 3;
			else if (ret == 1)
				i += 2;
			else if (ret == 0)
				i += 1;
			else
				return (1);
		}
		else
		{
			if ((ret = read_arg(c, av[i])))
				return (ret);
			++i;
		}
	}
	return (0);
}
