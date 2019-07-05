/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:03:11 by efouille          #+#    #+#             */
/*   Updated: 2019/03/25 15:16:27 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_types.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*elem;

	if (!f || !lst)
		return (NULL);
	elem = f(lst);
	ret = elem;
	lst = lst->next;
	while (lst)
	{
		elem->next = f(lst);
		elem = elem->next;
		lst = lst->next;
	}
	return (ret);
}
