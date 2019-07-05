/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:40:38 by efouille          #+#    #+#             */
/*   Updated: 2019/05/14 22:00:17 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "lftio.h"
#include "ft_printf.h"
#include "libft_const.h"
#include <unistd.h>

/*
** instruction aff from corewar assembly language
**
** instruction args
**		(register)	arg0 - char code to display
**
** display ascii arg0
**
** func input	: c	- the corewar structure
**				  i	- the caller exec
**
** func output	: none
*/

void	cw_aff(t_corewar *c, int i)
{
	t_args	*a;
	int		chr;

	if (c->show_aff)
	{
		a = c->procs[i]->exec->a;
		if (invalid_args(c->procs[i]->exec->opcode, a))
			return ;
		get_reg(c, i, get_arg(c, i, 0, USE_VALUE), &chr);
		chr %= 256;
		write(1, &chr, 1);
		if (c->verbose & V_OP)
			verbose(c, i);
	}
}
