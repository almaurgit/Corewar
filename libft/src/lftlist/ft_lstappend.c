/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 13:38:21 by efouille          #+#    #+#             */
/*   Updated: 2019/03/25 15:15:52 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_types.h"

void	ft_lstappend(t_list **alst, t_list *new)
{
	t_list	*t;

	if (alst)
	{
		if (*alst)
		{
			t = *alst;
			while (t->next)
				t = t->next;
			t->next = new;
		}
		else
		{
			*alst = new;
		}
	}
}
