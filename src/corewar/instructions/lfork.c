/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:39:02 by efouille          #+#    #+#             */
/*   Updated: 2019/05/22 20:01:52 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "lftio.h"
#include "lftlib.h"
#include "ft_printf.h"
#include "libft_const.h"

/*
** instruction fork from corewar assembly language
**
** instruction args
**		(direct)	arg0 - destination for the process
**
** spawns a new process at current PC + arg0
**
** func input	: c	- the corewar structure
**				  i	- the caller exec
**
** func output	: none
*/

void	cw_lfork(t_corewar *c, int i)
{
	t_args	*a;
	int		dst;

	a = c->procs[i]->exec->a;
	if (invalid_args(c->procs[i]->exec->opcode, a))
		return ;
	dst = c->procs[i]->pc + get_larg(c, i, 0, USE_CONTENT);
	rotate_pc(&dst);
	fork_proc(c, i, dst);
	if (c->verbose & V_OP)
		verbose(c, i);
}
