/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 23:00:41 by Edgar             #+#    #+#             */
/*   Updated: 2019/03/25 15:20:39 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_types.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	k;

	k = 0;
	while (k < len)
		((t_uchar*)b)[k++] = (t_uchar)c;
	return (b);
}
