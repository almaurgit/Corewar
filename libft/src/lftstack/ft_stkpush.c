/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 19:31:27 by efouille          #+#    #+#             */
/*   Updated: 2019/03/25 15:00:05 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lftlist.h"

void	ft_stkpush(t_stack **astk, t_stack *new)
{
	ft_lstappend((t_list**)astk, (t_list*)new);
}
