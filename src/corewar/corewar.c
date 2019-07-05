/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 05:08:00 by efouille          #+#    #+#             */
/*   Updated: 2019/06/04 22:16:11 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "lftstring.h"

static int	check_help_arg(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (!ft_strcmp("-h", av[i]) || !ft_strcmp("--help", av[i]))
		{
			usage();
			return (1);
		}
	}
	return (0);
}

static void	init(t_corewar *c)
{
	ft_bzero(c, sizeof(t_corewar));
	ft_memset(c->owner, -1, MEM_SIZE);
	ft_memset(c->pc, -1, MEM_SIZE);
	ft_bzero(c->mem, MEM_SIZE);
	c->cycles = 1;
	c->cycles_to_die = CYCLE_TO_DIE;
	c->next_kill = CYCLE_TO_DIE;
}

static int	load(t_corewar *c)
{
	if (c->nplayers == 0)
		return (cw_no_programs);
	else if (create_first_procs(c))
		return (cw_no_first_procs);
	return (0);
}

static void	run(t_corewar *c)
{
	if (c->tui)
		init_tui(c);
	else
		introduce_contestants(c);
	corewar_loop(c);
	if (c->tui)
		endwin();
}

int			main(int ac, char **av)
{
	t_corewar	corewar;
	int			ret;

	if (ac > 1)
	{
		if (check_help_arg(ac, av))
			return (0);
		init(&corewar);
		ret = read_args(&corewar, ac, av);
		if (!ret && !(ret = load(&corewar)))
			run(&corewar);
		else
			error(ret, 0);
		clean_procs(&corewar);
		clean_players(&corewar);
		return (ret);
	}
	usage();
	return (1);
}
