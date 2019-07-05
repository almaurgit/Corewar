/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelfirst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 14:54:31 by efouille          #+#    #+#             */
/*   Updated: 2019/03/25 15:16:41 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_types.h"
#include <stdlib.h>

void	ft_lstdelfirst(t_list **lst)
{
	t_list	*tmp;

	tmp = (*lst)->next;
	free((*lst)->content);
	*lst = tmp;
}
