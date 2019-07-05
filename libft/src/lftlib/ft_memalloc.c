/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 16:54:34 by Edgar             #+#    #+#             */
/*   Updated: 2019/03/25 15:27:10 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*ret;
	size_t	k;

	ret = malloc(size * sizeof(char));
	if (!ret)
		return (NULL);
	k = 0;
	while (k < size)
		((char*)ret)[k++] = 0;
	return (ret);
}
