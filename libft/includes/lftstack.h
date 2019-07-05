/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lftstack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 23:27:13 by efouille          #+#    #+#             */
/*   Updated: 2019/03/30 08:47:48 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFTSTACK_H
# define LFTSTACK_H

# include "libft_types.h"

t_stack	*ft_stknew(const void *content, size_t content_size);
void	ft_stkpush(t_stack **astk, t_stack *new);
t_stack	*ft_stkpop(t_stack *stk);

#endif
