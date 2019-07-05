/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:00:40 by efouille          #+#    #+#             */
/*   Updated: 2019/04/24 16:32:02 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "lftio.h"
#include "lftmath.h"
#include "ft_printf.h"
#include "libft_const.h"

/*
** instruction sti from corewar assembly language
**
** instruction args
**		(register)						arg0 - the value to store
**		(register | direct | indirect)	arg1 - first address operand
**		(register | direct)				arg2 - second address operand
**
** stores arg0 to address PC + (arg1 + arg2) % IDX_MOD
**
** func input	: c	- the corewar structure
**				  i	- the caller exec
**
** func output	: none
*/

void	cw_sti(t_corewar *c, int i)
{
	t_args	*a;
	int		r;
	int		dst;

	a = c->procs[i]->exec->a;
	if (invalid_args(c->procs[i]->exec->opcode, a))
		return ;
	r = get_arg(c, i, 0, USE_CONTENT);
	dst = get_arg(c, i, 1, USE_CONTENT);
	dst += get_arg(c, i, 2, USE_CONTENT);
	dst = c->procs[i]->pc + dst % IDX_MOD;
	rotate_pc(&dst);
	ft_swapbytes((t_u8*)&r, REG_SIZE);
	write_mem(c, dst, (t_u8*)&r, REG_SIZE);
	write_owner(c, dst, c->procs[i]->player, REG_SIZE);
	if (c->verbose & V_OP)
		verbose(c, i);
}
