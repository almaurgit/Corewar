/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_gen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 00:26:35 by efouille          #+#    #+#             */
/*   Updated: 2019/06/04 00:28:16 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_types.h"

t_op	op_first(char *name, int argc, t_u8 opcode, int n_cycles)
{
	t_op	op;

	op.name = name;
	op.argc = argc;
	op.opcode = opcode;
	op.n_cycles = n_cycles;
	return (op);
}

void	op_second(t_op *op, t_u8 has_ocp, t_u8 is_index, t_ins ins)
{
	op->has_ocp = has_ocp;
	op->is_index = is_index;
	op->ins = ins;
}

void	op_args(t_op *op, t_u8 arg0, t_u8 arg1, t_u8 arg2)
{
	op->arg_types[0] = arg0;
	op->arg_types[1] = arg1;
	op->arg_types[2] = arg2;
	op->arg_types[3] = 0;
}
