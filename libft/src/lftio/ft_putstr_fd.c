/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 13:14:26 by efouille          #+#    #+#             */
/*   Updated: 2019/05/27 19:09:12 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lftstring.h"
#include <unistd.h>

void	ft_putstr_fd(const char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}
