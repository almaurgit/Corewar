/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 02:32:28 by efouille          #+#    #+#             */
/*   Updated: 2019/05/21 17:43:01 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	invalid_args(int opcode, t_args *a)
{
	int		i;
	t_u8	argt;

	i = 0;
	while (i < a->argc)
	{
		argt = 0;
		if (a->argt[i] == REG_CODE)
			argt = T_REG;
		else if (a->argt[i] == DIR_CODE)
			argt = T_DIR;
		else if (a->argt[i] == IND_CODE)
			argt = T_IND;
		if (!(argt & ops()[opcode - 1].arg_types[i]))
			return (1);
		++i;
	}
	return (0);
}
