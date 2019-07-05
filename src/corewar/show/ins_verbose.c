/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_verbose.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 02:38:49 by efouille          #+#    #+#             */
/*   Updated: 2019/05/28 08:15:15 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "lftio.h"
#include "ft_printf.h"
#include "libft_const.h"

static void	print_arg(t_args *a, t_op *op, int arg)
{
	if (a->argt[arg] == REG_CODE)
		ft_putstr(SH_YELLOW);
	else if (a->argt[arg] == IND_CODE)
		ft_putstr(SH_RED);
	else if (a->argt[arg] == DIR_CODE && op->is_index)
		ft_putstr(SH_RED);
	else
		ft_putstr(SH_GREEN);
	if (a->argt[arg] == REG_CODE)
		ft_putchar('r');
	else if (a->argt[arg] == DIR_CODE)
		ft_putchar('%');
	if (op->is_index)
		ft_printf("%hd ", a->args[arg]);
	else
		ft_printf("%d ", a->args[arg]);
	ft_putstr(SH_DEFAULT);
}

void		verbose(t_corewar *c, int i)
{
	t_args	*a;
	t_op	*op;
	int		arg;

	a = c->procs[i]->exec->a;
	op = &ops()[c->procs[i]->exec->opcode - 1];
	ft_printf("%s{%4d} : %s%s ", SH_BLUE, i, op->name, SH_DEFAULT);
	arg = 0;
	while (arg < a->argc)
	{
		print_arg(a, op, arg);
		++arg;
	}
	ft_putchar('\n');
}
