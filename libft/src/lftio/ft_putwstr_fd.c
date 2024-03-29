/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 00:54:49 by efouille          #+#    #+#             */
/*   Updated: 2019/03/23 08:57:15 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lftio.h"

void	ft_putwstr_fd(wchar_t *s, int fd)
{
	while (*s)
		ft_putwchar_fd(*(s++), fd);
}
