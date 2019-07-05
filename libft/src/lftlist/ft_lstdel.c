/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 02:10:16 by Edgar             #+#    #+#             */
/*   Updated: 2019/03/25 15:26:36 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lftlib.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	if (alst && *alst && del)
	{
		del((*alst)->content, (*alst)->content_size);
		if ((*alst)->next)
			ft_lstdel(&((*alst)->next), del);
		ft_memdel((void**)(alst));
	}
}
