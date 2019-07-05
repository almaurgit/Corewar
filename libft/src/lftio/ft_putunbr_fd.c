/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 19:58:47 by efouille          #+#    #+#             */
/*   Updated: 2019/05/27 19:09:26 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lftio.h"

void	ft_putunbr_fd(t_umax n, int fd)
{
	if (n >= 10)
	{
		ft_putunbr_fd(n / 10, fd);
		ft_putunbr_fd(n % 10, fd);
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
	}
}
