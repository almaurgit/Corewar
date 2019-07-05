/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:11:22 by efouille          #+#    #+#             */
/*   Updated: 2019/05/22 19:03:13 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_types.h"
#include "ft_printf.h"
#include "libft_const.h"

void	error(int e, char *arg)
{
	ft_dprintf(2, "%s[FAIL]%s : ", SH_RED, SH_DEFAULT);
	if (e == cw_header_error)
		ft_dprintf(2, "invalid header\n");
	else if (e == cw_malloc_error)
		ft_dprintf(2, "malloc failure\n");
	else if (e == cw_open_error)
		ft_dprintf(2, "can't open %s\n", arg);
	else if (e == cw_magic_error)
		ft_dprintf(2, "invalid magic number.\n");
	else if (e == cw_size_error)
		ft_dprintf(2, "champion is too fat\n");
	else if (e == cw_number_error)
		ft_dprintf(2, "invalid number for champ (option -n)\n");
	else if (e == cw_no_programs)
		ft_dprintf(2, "no program to execute\n");
	else if (e == cw_no_first_procs)
		ft_dprintf(2, "could not create first processes\n");
	else
		ft_dprintf(2, "unknown error %d %s\n", e, arg);
}
