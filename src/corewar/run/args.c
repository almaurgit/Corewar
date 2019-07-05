/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:49:28 by efouille          #+#    #+#             */
/*   Updated: 2019/05/21 17:44:53 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "lftmath.h"

static int	get_dir(int arg, t_process *proc, t_args *a)
{
	int	ret;

	if (ops()[proc->exec->opcode - 1].is_index)
		ret = (short)a->args[arg];
	else
		ret = a->args[arg];
	return (ret);
}

static int	get_ind(t_corewar *c, int arg, t_u8 use_content, t_process *proc)
{
	int			ret;
	t_args		*a;
	int			addr;

	ret = 0;
	a = proc->exec->a;
	if (use_content)
	{
		addr = proc->pc + (short)a->args[arg] % IDX_MOD;
		read_mem(c, addr, (t_u8*)&ret, REG_SIZE);
		ft_swapbytes((t_u8*)&ret, REG_SIZE);
	}
	else
		ret = (short)a->args[arg];
	return (ret);
}

int			get_arg(t_corewar *c, int i, int arg, t_u8 use_content)
{
	int			ret;
	t_process	*proc;
	t_args		*a;

	proc = c->procs[i];
	a = proc->exec->a;
	ret = 0;
	if (a->argt[arg] == REG_CODE && use_content)
		get_reg(c, i, a->args[arg], &ret);
	else if (a->argt[arg] == REG_CODE && !use_content)
		ret = a->args[arg];
	else if (a->argt[arg] == DIR_CODE)
		ret = get_dir(arg, proc, a);
	else
		ret = get_ind(c, arg, use_content, proc);
	return (ret);
}

int			get_larg(t_corewar *c, int i, int arg, t_u8 use_content)
{
	int			ret;
	t_process	*proc;
	t_args		*a;

	proc = c->procs[i];
	a = proc->exec->a;
	if (a->argt[arg] == REG_CODE && use_content)
		get_reg(c, i, a->args[arg], &ret);
	else if (a->argt[arg] == REG_CODE && !use_content)
		ret = a->args[arg];
	else if (a->argt[arg] == DIR_CODE)
		ret = get_dir(arg, proc, a);
	else
	{
		if (use_content)
		{
			read_mem(c, proc->pc + (short)a->args[arg], (t_u8*)&ret, REG_SIZE);
			ft_swapbytes((t_u8*)&ret, REG_SIZE);
		}
		else
			ret = (short)a->args[arg];
	}
	return (ret);
}
