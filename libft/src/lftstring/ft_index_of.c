/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_of.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:37:54 by Edgar             #+#    #+#             */
/*   Updated: 2019/03/24 10:40:10 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lftstring.h"

/*
** gives the index of the first occurence of c in s
**
** input :	s	- the string to search in
**			c	- the character to search
**
** output :	(int) the index of first occurence of c in s
*/

int	ft_index_of(const char *s, char c)
{
	return (ft_index_of_nth(s, c, 0));
}
