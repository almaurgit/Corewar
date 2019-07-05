/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stknew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 19:29:52 by efouille          #+#    #+#             */
/*   Updated: 2019/03/25 14:59:49 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lftlist.h"

t_stack	*ft_stknew(const void *content, size_t content_size)
{
	return ((t_stack*)ft_lstnew(content, content_size));
}
