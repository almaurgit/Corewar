/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:00:40 by efouille          #+#    #+#             */
/*   Updated: 2019/05/15 14:04:27 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "lftio.h"
#include "lftmath.h"
#include "ft_printf.h"
#include "libft_const.h"

/*
** instruction ld from corewar assembly language
**
** instruction args
**		(direct | indirect)	arg0 - the value to store
**		(register)			arg1 - the register that gets the value
**
** stores (direct)arg0 or value at PC + (indirect)arg0 % IDX_MOD
** to register arg1
**
** carry : carry = arg0 == 0
**
** func input	: c	- the corewar structure
**				  i	- the caller exec
**
** func output	: none
*/

void	cw_ld(t_corewar *c, int i)
{
	t_args	*a;
	int		r;

	a = c->procs[i]->exec->a;
	if (invalid_args(c->procs[i]->exec->opcode, a))
		return ;
	r = get_arg(c, i, 0, USE_CONTENT);
	c->procs[i]->carry = !r;
	set_reg(c, i, get_arg(c, i, 1, USE_VALUE), r);
	if (c->verbose & V_OP)
		verbose(c, i);
}
