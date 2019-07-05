/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 01:56:30 by Edgar             #+#    #+#             */
/*   Updated: 2019/03/24 10:40:50 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lftstring.h"
#include <stdlib.h>

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*lst;

	lst = (t_list*)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	if (!content)
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	else
	{
		lst->content = malloc(content_size);
		if (!(lst->content))
		{
			free(lst);
			return (NULL);
		}
		ft_memcpy(lst->content, content, content_size);
		lst->content_size = content_size;
	}
	lst->next = NULL;
	return (lst);
}
