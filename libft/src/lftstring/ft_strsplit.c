/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:27:26 by efouille          #+#    #+#             */
/*   Updated: 2019/03/24 10:56:10 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lftstring.h"
#include <stdlib.h>

/*
** fills the array with substrings
**
** input :	s		- the string to cut
**			c		- the delimiter
**			ret		- the array of substrings to fill
**			nb_subs	- the number of substrings
**
** output :	nothing
*/

static void	fill_array(const char *s, char c, char **ret, int nb_subs)
{
	int		k;
	int		l;
	size_t	start;

	k = 0;
	l = 0;
	while (l < nb_subs)
	{
		while (s[k] == c)
			k++;
		start = k;
		while (s[k] && s[k] != c)
		{
			k++;
		}
		ret[l] = ft_strsub(s, start, k - start);
		k++;
		l++;
	}
}

char		**ft_strsplit(const char *s, char c)
{
	int		k;
	int		nb_subs;
	char	**ret;

	if (!s)
		return (NULL);
	nb_subs = 0;
	k = 0;
	while (s[k])
	{
		if (s[k] != c && (s[k + 1] == c || s[k + 1] == '\0'))
			nb_subs++;
		k++;
	}
	ret = (char**)malloc((nb_subs + 1) * sizeof(char*));
	if (!ret)
		return (NULL);
	fill_array(s, c, ret, nb_subs);
	ret[nb_subs] = NULL;
	return (ret);
}
