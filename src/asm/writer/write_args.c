/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 17:57:44 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/04 14:47:40 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "lftlib.h"
#include "lftmath.h"
#include "lftstring.h"
#include <unistd.h>

/*
**	Write a register arg in the .cor file
*/

static void		write_register_arg(int fd, char *arg)
{
	unsigned int	c;

	c = (unsigned int)ft_atoumax(arg + 1);
	write(fd, &c, REG_WRITE_SIZE);
}

/*
**	Write an indirect arg in the .cor file (if the arg type is label,
**	write the difference between the label's PC and the current instru PC)
*/

static void		write_indirect_arg(t_data *da, int fd, t_instru *in, char *arg)
{
	unsigned int	c;

	if (!ft_strchr(arg, LABEL_CHAR))
		c = ft_atoi(arg);
	else
		c = ((get_label_by_name(da, arg + 1)->pc)
				- get_pc_instru(da, in));
	c = (short)c;
	ft_swapbytes((uint8_t *)&c, IND_WRITE_SIZE);
	write(fd, &c, 2);
}

/*
**	Write an direct arg in the .cor file (if the arg type is label,
**	write the difference between the label's PC and the current instru PC)
*/

static void		write_direct_arg(t_data *da, int fd, t_instru *inst, char *arg)
{
	unsigned int	c;

	if (!ft_strchr(arg, LABEL_CHAR))
		c = ft_atoi(arg + 1);
	else
		c = (short)((get_label_by_name(da, arg + 2)->pc)
				- get_pc_instru(da, inst));
	if (inst->op->dir_size == 0)
		ft_swapbytes((uint8_t *)&c, 4);
	else
		ft_swapbytes((uint8_t *)&c, 2);
	write(fd, &c, (inst->op->dir_size == 0 ? DIR_WRITE_SIZE : IND_WRITE_SIZE));
}

/*
**	Return the code of the given arg (can be 1, 2, or 3)
*/

unsigned int	get_arg_code(char *arg)
{
	if (arg[0] == DIRECT_CHAR)
		return (DIR_CODE);
	if (arg[0] == REGISTER_CHAR)
		return (REG_CODE);
	return (IND_CODE);
}

/*
**	Write all the arguments of an instruction in the .cor file
*/

void			write_args(t_data *data, int fd, t_instru *instru)
{
	int				i;
	char			*arg;
	unsigned int	type;

	i = 0;
	while (i < instru->op->nb_params)
	{
		arg = instru->args[i];
		type = get_arg_type(arg);
		if (type == T_REG)
			write_register_arg(fd, arg);
		else if (type == T_IND)
			write_indirect_arg(data, fd, instru, arg);
		else if (type == T_DIR)
			write_direct_arg(data, fd, instru, arg);
		i++;
	}
}
