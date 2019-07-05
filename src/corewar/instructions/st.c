/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:35:34 by efouille          #+#    #+#             */
/*   Updated: 2019/04/24 16:32:06 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "lftio.h"
#include "lftmath.h"
#include "ft_printf.h"
#include "libft_const.h"

/*
** instruction st from corewar assembly language
**
** instruction args
**		(register)				arg0 - the value to store
**		(indirect | register)	arg1 - the address/register that gets the value
**
** stores arg0 to address PC + (indirect)arg1 % IDX_MOD or register arg1
**
** func input	: c	- the corewar structure
**				  i	- the caller exec
**
** func output	: none
*/

void	cw_st(t_corewar *c, int i)
{
	t_args	*a;
	int		r;
	int		dst;

	a = c->procs[i]->exec->a;
	if (invalid_args(c->procs[i]->exec->opcode, a))
		return ;
	r = get_arg(c, i, 0, USE_CONTENT);
	if (a->argt[1] == IND_CODE)
	{
		ft_swapbytes((t_u8*)&r, REG_SIZE);
		dst = c->procs[i]->pc + get_arg(c, i, 1, USE_VALUE) % IDX_MOD;
		write_mem(c, dst, (t_u8*)&r, REG_SIZE);
		write_owner(c, dst, c->procs[i]->player, REG_SIZE);
	}
	else
		set_reg(c, i, get_arg(c, i, 1, USE_VALUE), r);
	if (c->verbose & V_OP)
		verbose(c, i);
}
