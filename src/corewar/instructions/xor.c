/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:22:57 by efouille          #+#    #+#             */
/*   Updated: 2019/05/22 20:00:39 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "lftio.h"
#include "ft_printf.h"
#include "libft_const.h"

/*
** instruction xor from corewar assembly language
**
** instruction args
**		(register | direct | indirect)	arg0 - first operand
**		(register | direct | indirect)	arg1 - second operand
**		(register)						arg2 - destination of the operation
**
** stores arg0 ^ arg1 to arg2
**
** func input	: c	- the corewar structure
**				  i	- the caller exec
**
** func output	: none
*/

void	cw_xor(t_corewar *c, int i)
{
	t_args	*a;
	int		r;

	a = c->procs[i]->exec->a;
	if (invalid_args(c->procs[i]->exec->opcode, a))
		return ;
	r = get_arg(c, i, 0, USE_CONTENT) ^ get_arg(c, i, 1, USE_CONTENT);
	set_reg(c, i, get_arg(c, i, 2, USE_VALUE), r);
	c->procs[i]->carry = !r;
	if (c->verbose & V_OP)
		verbose(c, i);
}
