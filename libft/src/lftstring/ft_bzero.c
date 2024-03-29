/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 23:06:56 by Edgar             #+#    #+#             */
/*   Updated: 2019/03/25 15:19:01 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_types.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	k;

	k = 0;
	while (k < n)
		((char*)s)[k++] = 0;
}
