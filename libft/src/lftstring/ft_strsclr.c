/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsclr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 12:40:50 by efouille          #+#    #+#             */
/*   Updated: 2019/03/25 15:28:09 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** same as strclr but from index s of str
**
** input :	s	- the index where clear starts
** 			n	- max size
**
** output :	none
*/

void	ft_strsclr(char *str, int s, int n)
{
	if (str)
	{
		while (s < n)
		{
			str[s] = '\0';
			s++;
		}
	}
}
