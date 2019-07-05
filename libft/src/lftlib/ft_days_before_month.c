/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_days_before_month.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 03:54:07 by efouille          #+#    #+#             */
/*   Updated: 2019/03/25 15:05:53 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lftlib.h"

t_uint	ft_days_before_month(t_uint m, t_uint y)
{
	if (m == 1)
		return (0);
	else if (m == 2)
		return (31);
	else if (m == 3)
		return (ft_days_before_month(2, y) + 28 + ft_yearisleap(y));
	else if (m == 4)
		return (ft_days_before_month(3, y) + 31);
	else if (m == 5)
		return (ft_days_before_month(4, y) + 30);
	else if (m == 6)
		return (ft_days_before_month(5, y) + 31);
	else if (m == 7)
		return (ft_days_before_month(6, y) + 30);
	else if (m == 8)
		return (ft_days_before_month(7, y) + 31);
	else if (m == 9)
		return (ft_days_before_month(8, y) + 31);
	else if (m == 10)
		return (ft_days_before_month(9, y) + 30);
	else if (m == 11)
		return (ft_days_before_month(10, y) + 31);
	else
		return (ft_days_before_month(11, y) + 30);
}
