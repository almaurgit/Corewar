/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 02:11:46 by rlegan            #+#    #+#             */
/*   Updated: 2019/06/04 18:47:02 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"
#include "lftstring.h"

/*
**	Assign for a op structure its name, its number of arguments
**	and its id.
*/

t_op	op_first(char *name, int argc, int id)
{
	t_op	op;

	op.name = name;
	op.nb_params = argc;
	op.id = id;
	return (op);
}

/*
**	Assign for a given op structure its encoding byte, and if its
**	right dir_size
*/

void	op_second(t_op *op, int encoding_byte, int dir_size)
{
	op->encoding_byte = encoding_byte;
	op->dir_size = dir_size;
}

/*
**	Assign for a given op structure its different parameters type.
*/

void	op_args(t_op *op, char arg0, char arg1, char arg2)
{
	op->params_type[0] = arg0;
	op->params_type[1] = arg1;
	op->params_type[2] = arg2;
}
