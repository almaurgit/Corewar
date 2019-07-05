/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xtra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 03:26:27 by efouille          #+#    #+#             */
/*   Updated: 2019/06/04 19:58:47 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include <stdlib.h>

t_printer	ft_printf_xtra_printer(char c, t_printer p, int mode)
{
	static t_printer	printers[128];

	if (c < 0)
	{
		return (NULL);
	}
	if (mode == PRINTF_XTRA_GET)
	{
		return (printers[(int)c]);
	}
	else if (mode == PRINTF_XTRA_SET)
	{
		printers[(int)c] = p;
		return (printers[(int)c]);
	}
	return (NULL);
}

int			improve_ftprintf(char c, t_printer p)
{
	if (!ft_printf_xtra_printer(c, p, PRINTF_XTRA_SET))
		return (0);
	return (1);
}
