/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfmantissa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 19:26:35 by Edgar             #+#    #+#             */
/*   Updated: 2019/03/25 15:17:25 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_types.h"

int	ft_getfmantissa(float n)
{
	t_float	tmp;

	tmp = *(t_float*)&n;
	return (tmp.mantissa);
}
