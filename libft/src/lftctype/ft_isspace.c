/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 00:59:15 by efouille          #+#    #+#             */
/*   Updated: 2019/06/04 17:20:14 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** check whether c is a space or not
**
** input :	c	- the character to check
**
** output :	(int) 1 if c is a space, 0 if not
*/

int	ft_isspace(int c)
{
	if (c == '\n' || c == '\t' || c == '\v')
		return (1);
	else if (c == ' ' || c == '\f' || c == '\r')
		return (1);
	return (0);
}
