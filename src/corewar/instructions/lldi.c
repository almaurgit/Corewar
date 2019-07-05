/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 01:53:34 by efouille          #+#    #+#             */
/*   Updated: 2019/05/28 05:53:29 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "lftio.h"
#include "lftmath.h"
#include "ft_printf.h"
#include "libft_const.h"

/*
** instruction lldi from corewar assembly language
**
** instruction args
**		(register)						arg0 - the value to store
**		(register | direct | indirect)	arg1 - first address operand
**		(register | direct)				arg2 - second address operand
**
** stores arg0 to address PC + (arg1 + arg2)
**
** func input	: c	- the corewar structure
**				  i	- the caller exec
**
** func output	: none
*/

void	cw_lldi(t_corewar *c, int i)
{
	t_args	*a;
	int		r;
	int		src;

	a = c->procs[i]->exec->a;
	if (invalid_args(c->procs[i]->exec->opcode, a))
		return ;
	src = get_larg(c, i, 0, USE_CONTENT) + get_larg(c, i, 1, USE_CONTENT);
	src = c->procs[i]->pc + src;
	read_mem(c, src, (t_u8*)&r, REG_SIZE);
	ft_swapbytes((t_u8*)&r, REG_SIZE);
	set_reg(c, i, get_larg(c, i, 2, USE_VALUE), r);
	c->procs[i]->carry = !r;
	if (c->verbose & V_OP)
		verbose(c, i);
}
