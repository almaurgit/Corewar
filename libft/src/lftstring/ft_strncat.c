/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 18:26:20 by Edgar             #+#    #+#             */
/*   Updated: 2019/03/25 15:21:35 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_types.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		k;
	size_t	l;

	k = 0;
	l = 0;
	while (s1[k])
		k++;
	while (s2[l] && l < n)
		s1[k++] = s2[l++];
	if (l < n)
		s1[k] = '\0';
	return (s1);
}
