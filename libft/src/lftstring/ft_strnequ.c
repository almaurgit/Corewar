/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 17:54:13 by Edgar             #+#    #+#             */
/*   Updated: 2019/03/25 15:22:21 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_types.h"

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t	k;

	if (!s1 || !s2)
		return (0);
	if (!n)
		return (1);
	k = 0;
	while (s1[k] == s2[k] && s1[k] && s2[k] && k < n)
		k++;
	if (k == n)
		k--;
	return (s1[k] == s2[k]);
}
