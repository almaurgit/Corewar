/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:14:34 by efouille          #+#    #+#             */
/*   Updated: 2019/05/22 20:01:35 by efouille         ###   ########.fr       */
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
** spawns a new process at current PC + arg0 % IDX_MOD
**
** func input	: c	- the corewar structure
**				  i	- the caller exec
**
** func output	: none
*/

void	cw_fork(t_corewar *c, int i)
{
	t_args	*a;
	int		dst;

	a = c->procs[i]->exec->a;
	if (invalid_args(c->procs[i]->exec->opcode, a))
		return ;
	dst = c->procs[i]->pc + get_arg(c, i, 0, USE_CONTENT) % IDX_MOD;
	rotate_pc(&dst);
	fork_proc(c, i, dst);
	if (c->verbose & V_OP)
		verbose(c, i);
}
