/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:31:18 by efouille          #+#    #+#             */
/*   Updated: 2019/04/18 01:44:07 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_types.h"
#include "corewar_const.h"

void	set_reg(t_corewar *c, int proc, int reg, int val)
{
	if (reg > 0 && reg <= REG_NUMBER && proc < c->nprocs)
		c->procs[proc]->reg[reg - 1] = val;
}

void	get_reg(t_corewar *c, int proc, int reg, int *val)
{
	if (reg > 0 && reg <= REG_NUMBER && proc < c->nprocs)
		*val = c->procs[proc]->reg[reg - 1];
}
