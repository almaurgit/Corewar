/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblankspace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 18:56:41 by efouille          #+#    #+#             */
/*   Updated: 2019/03/23 23:36:11 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** check whether c is a blank space or not
**
** input :	c	- the character to check
**
** output :	(int) 1 if c is a blank space, 0 if not
*/

int	ft_isblankspace(int c)
{
	return ((c == '\n') || (c == '\t') || (c == ' '));
}
