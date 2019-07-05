/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2019/06/04 02:18:54 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"
#include "lftstring.h"

/*
**	Init the third part of the operations table
*/

static void		ops3(t_op *op_tab)
{
	op_tab[15] = op_first("aff", 1, 16);
	op_second(&(op_tab[15]), 1, 0);
	op_args(&(op_tab[15]), T_REG, 0, 0);
}

/*
**	Init the second part of the operations table
*/

static void		ops2(t_op *op_tab)
{
	op_tab[7] = op_first("xor", 3, 8);
	op_second(&(op_tab[7]), 1, 0);
	op_args(&(op_tab[7]), T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG);
	op_tab[8] = op_first("zjmp", 1, 9);
	op_second(&(op_tab[8]), 0, 1);
	op_args(&(op_tab[8]), T_DIR, 0, 0);
	op_tab[9] = op_first("ldi", 3, 10);
	op_second(&(op_tab[9]), 1, 1);
	op_args(&(op_tab[9]), T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG);
	op_tab[10] = op_first("sti", 3, 11);
	op_second(&(op_tab[10]), 1, 1);
	op_args(&(op_tab[10]), T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR);
	op_tab[11] = op_first("fork", 1, 12);
	op_second(&(op_tab[11]), 0, 1);
	op_args(&(op_tab[11]), T_DIR, 0, 0);
	op_tab[12] = op_first("lld", 2, 13);
	op_second(&(op_tab[12]), 1, 0);
	op_args(&(op_tab[12]), T_DIR | T_IND, T_REG, 0);
	op_tab[13] = op_first("lldi", 3, 14);
	op_second(&(op_tab[13]), 1, 1);
	op_args(&(op_tab[13]), T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG);
	op_tab[14] = op_first("lfork", 1, 15);
	op_second(&(op_tab[14]), 0, 1);
	op_args(&(op_tab[14]), T_DIR, 0, 0);
	ops3(op_tab);
}

/*
**	Init all the operations, and save it in the data global structure
*/

void			init_ops(t_data *data)
{
	static t_op	op_tab[16];

	op_tab[0] = op_first("live", 1, 1);
	op_second(&(op_tab[0]), 0, 0);
	op_args(&(op_tab[0]), T_DIR, 0, 0);
	op_tab[1] = op_first("ld", 2, 2);
	op_second(&(op_tab[1]), 1, 0);
	op_args(&(op_tab[1]), T_DIR | T_IND, T_REG, 0);
	op_tab[2] = op_first("st", 2, 3);
	op_second(&(op_tab[2]), 1, 0);
	op_args(&(op_tab[2]), T_REG, T_IND | T_REG, 0);
	op_tab[3] = op_first("add", 3, 4);
	op_second(&(op_tab[3]), 1, 0);
	op_args(&(op_tab[3]), T_REG, T_REG, T_REG);
	op_tab[4] = op_first("sub", 3, 5);
	op_second(&(op_tab[4]), 1, 0);
	op_args(&(op_tab[4]), T_REG, T_REG, T_REG);
	op_tab[5] = op_first("and", 3, 6);
	op_second(&(op_tab[5]), 1, 0);
	op_args(&(op_tab[5]), T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG);
	op_tab[6] = op_first("or", 3, 7);
	op_second(&(op_tab[6]), 1, 0);
	op_args(&(op_tab[6]), T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG);
	ops2(op_tab);
	data->ops_table = op_tab;
}

/*
**	Given a name, return the op structure which correponds
*/

t_op			*get_op_by_name(t_data *data, char *name)
{
	int		i;
	t_op	*ops;

	i = -1;
	ops = data->ops_table;
	while (++i < OP_COUNT)
	{
		if (ft_strequ(ops[i].name, name))
			return (&ops[i]);
	}
	return (NULL);
}
