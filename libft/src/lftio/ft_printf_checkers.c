/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_checkers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:41:53 by efouille          #+#    #+#             */
/*   Updated: 2019/06/04 17:17:13 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_const.h"
#include "lftstring.h"

int	known_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 's' || c == 'p' || c == 'd' || c == 'i')
		return (1);
	else if (c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'f')
		return (1);
	else if (c == 'F' || c == 'b' || c == 'B' || c == 'n' || c == '%')
		return (1);
	else if (c == 'C' || c == 'S' || c == 'D' || c == 'O' || c == 'U')
		return (1);
	else if (c == 'k')
		return (1);
	return (0);
}

int	valid_unknown_conversion(char c)
{
	int	cond;

	cond = ft_index_of(FLAGS, c) == -1 && ft_index_of(PRECISION, c) == -1;
	cond = cond && ft_index_of(MODIFIERS, c) == -1;
	if (cond)
		return (1);
	return (0);
}
