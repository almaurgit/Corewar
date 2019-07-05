/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 17:57:44 by lduqueno          #+#    #+#             */
/*   Updated: 2019/05/22 15:55:11 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft_types.h"

/*
**	Return the actual PC after the instru stop (including stop)
*/

unsigned int	get_pc_after(t_data *data, t_instru *stop)
{
	unsigned int	pc;
	t_instru		*tmp_instru;

	if (stop == NULL)
		return (0);
	pc = 0;
	tmp_instru = data->instrus;
	while (tmp_instru)
	{
		pc += tmp_instru->size_instru;
		if (tmp_instru == stop)
			break ;
		tmp_instru = tmp_instru->next;
	}
	return (pc);
}

/*
**	Return the actual PC before the instru stop (non including stop)
*/

unsigned int	get_pc_instru(t_data *data, t_instru *stop)
{
	unsigned int	pc;
	t_instru		*tmp_instru;

	if (stop == NULL)
		return (0);
	pc = 0;
	tmp_instru = data->instrus;
	while (tmp_instru)
	{
		if (tmp_instru == stop)
			break ;
		pc += tmp_instru->size_instru;
		tmp_instru = tmp_instru->next;
	}
	return (pc);
}
