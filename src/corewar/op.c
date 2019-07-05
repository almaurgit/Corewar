/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2019/06/04 00:26:42 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ops3(t_op *op_tab)
{
	op_tab[15] = op_first("aff", 1, 16, 2);
	op_second(&(op_tab[15]), 1, 0, cw_aff);
	op_args(&(op_tab[15]), T_REG, 0, 0);
}

static void	ops2(t_op *op_tab)
{
	op_tab[7] = op_first("xor", 3, 8, 6);
	op_second(&(op_tab[7]), 1, 0, cw_xor);
	op_args(&(op_tab[7]), T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG);
	op_tab[8] = op_first("zjmp", 1, 9, 20);
	op_second(&(op_tab[8]), 0, 1, cw_zjmp);
	op_args(&(op_tab[8]), T_DIR, 0, 0);
	op_tab[9] = op_first("ldi", 3, 10, 25);
	op_second(&(op_tab[9]), 1, 1, cw_ldi);
	op_args(&(op_tab[9]), T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG);
	op_tab[10] = op_first("sti", 3, 11, 25);
	op_second(&(op_tab[10]), 1, 1, cw_sti);
	op_args(&(op_tab[10]), T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR);
	op_tab[11] = op_first("fork", 1, 12, 800);
	op_second(&(op_tab[11]), 0, 1, cw_fork);
	op_args(&(op_tab[11]), T_DIR, 0, 0);
	op_tab[12] = op_first("lld", 2, 13, 10);
	op_second(&(op_tab[12]), 1, 0, cw_lld);
	op_args(&(op_tab[12]), T_DIR | T_IND, T_REG, 0);
	op_tab[13] = op_first("lldi", 3, 14, 50);
	op_second(&(op_tab[13]), 1, 1, cw_lldi);
	op_args(&(op_tab[13]), T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG);
	op_tab[14] = op_first("lfork", 1, 15, 1000);
	op_second(&(op_tab[14]), 0, 1, cw_lfork);
	op_args(&(op_tab[14]), T_DIR, 0, 0);
	ops3(op_tab);
}

t_op		*ops(void)
{
	static t_op	op_tab[16];

	op_tab[0] = op_first("live", 1, 1, 10);
	op_second(&(op_tab[0]), 0, 0, cw_live);
	op_args(&(op_tab[0]), T_DIR, 0, 0);
	op_tab[1] = op_first("ld", 2, 2, 5);
	op_second(&(op_tab[1]), 1, 0, cw_ld);
	op_args(&(op_tab[1]), T_DIR | T_IND, T_REG, 0);
	op_tab[2] = op_first("st", 2, 3, 5);
	op_second(&(op_tab[2]), 1, 0, cw_st);
	op_args(&(op_tab[2]), T_REG, T_IND | T_REG, 0);
	op_tab[3] = op_first("add", 3, 4, 10);
	op_second(&(op_tab[3]), 1, 0, cw_add);
	op_args(&(op_tab[3]), T_REG, T_REG, T_REG);
	op_tab[4] = op_first("sub", 3, 5, 10);
	op_second(&(op_tab[4]), 1, 0, cw_sub);
	op_args(&(op_tab[4]), T_REG, T_REG, T_REG);
	op_tab[5] = op_first("and", 3, 6, 6);
	op_second(&(op_tab[5]), 1, 0, cw_and);
	op_args(&(op_tab[5]), T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG);
	op_tab[6] = op_first("or", 3, 7, 6);
	op_second(&(op_tab[6]), 1, 0, cw_or);
	op_args(&(op_tab[6]), T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG);
	ops2(op_tab);
	return (op_tab);
}
