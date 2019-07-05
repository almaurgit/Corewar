/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 13:09:49 by efouille          #+#    #+#             */
/*   Updated: 2019/03/24 10:54:48 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lftlist.h"
#include "lftstring.h"

/*
** fills the list with substrings
**
** input :	s		- the string to cut
**			c		- the delimiter
**			ret		- the list of substrings to fill
**			nb_subs	- the number of substrings
**
** output :	nothing
*/

static void	fill_list(const char *s, char c, t_list **ret, int nb_subs)
{
	int		k;
	size_t	start;
	char	*tmp;

	k = 0;
	while (nb_subs--)
	{
		while (s[k] == c)
			k++;
		start = k;
		while (s[k] && s[k] != c)
		{
			k++;
		}
		tmp = ft_strsub(s, start, (k++) - start);
		ft_lstappend(ret, ft_lstnew(tmp, ft_strlen(tmp) + 1));
	}
}

t_list		*ft_strtolst(const char *s, char c)
{
	int		k;
	int		nb_subs;
	t_list	*ret;

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
	ret = NULL;
	fill_list(s, c, &ret, nb_subs);
	return (ret);
}
