/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lftlist.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 12:54:30 by efouille          #+#    #+#             */
/*   Updated: 2019/03/23 12:56:54 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFTLIST_H
# define LFTLIST_H

# include "libft_types.h"

void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstappend(t_list **alst, t_list *new);
void	ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void	ft_lstdelfirst(t_list **lst);
void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list	*ft_lstnew(const void *content, size_t content_size);

#endif
