/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 01:24:23 by efouille          #+#    #+#             */
/*   Updated: 2019/03/23 08:57:19 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lftio.h"

void	ft_putwstr(wchar_t *s)
{
	ft_putwstr_fd(s, 1);
}
