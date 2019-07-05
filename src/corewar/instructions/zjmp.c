/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:22:59 by efouille          #+#    #+#             */
/*   Updated: 2019/05/23 15:07:38 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "lftio.h"
#include "ft_printf.h"
#include "libft_const.h"

/*
** instruction zjmp from corewar assembly language
**
** instruction args
**		(direct)	arg0 - the destination address
**
** if the calling process has his carry set, zjmp jumps to PC + arg0 % IDX_MOD
** if the carry is not set, zjmp does nothing but takes the same time
**
** func input	: c	- the corewar structure
**				  i	- the caller exec
**
** func output	: none
*/

void	cw_zjmp(t_corewar *c, int i)
{
	t_args	*a;
	int		tmp;

	a = c->procs[i]->exec->a;
	if (invalid_args(c->procs[i]->exec->opcode, a))
		return ;
	if (c->procs[i]->carry)
	{
		tmp = (int)c->procs[i]->pc + ((short)a->args[0]) % IDX_MOD;
		rotate_pc(&tmp);
		c->procs[i]->pc = (int)tmp;
	}
	if (c->verbose & V_OP)
	{
		verbose(c, i);
		if (c->procs[i]->carry)
			ft_printf("         %sok%s\n", SH_GREEN, SH_DEFAULT);
		else
			ft_printf("         %sko%s\n", SH_RED, SH_DEFAULT);
	}
}
