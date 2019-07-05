/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nindex_of_nth.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:41:46 by Edgar             #+#    #+#             */
/*   Updated: 2019/03/17 00:54:10 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** gives the index of the n-th occurence of c in s
**
** input :	s	- the string to search in
**			c	- the character to search
**			n	- the occurence of c to search in s
**
** output :	(int) the index of the n-th occurence of c in s
*/

int	ft_nindex_of_nth(const char *s, char c, int n, int max)
{
	int	k;
	int	nth;

	k = 0;
	nth = 0;
	if (!s)
		return (-1);
	while (k < max && s[k])
	{
		if (s[k] == c)
		{
			if (n == nth)
				return (k);
			else
				nth++;
		}
		k++;
	}
	return (-1);
}
