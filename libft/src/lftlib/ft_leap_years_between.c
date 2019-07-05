/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leap_years_between.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 03:52:32 by efouille          #+#    #+#             */
/*   Updated: 2019/03/25 15:06:16 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lftlib.h"

t_uint	ft_leap_years_between(t_uint a, t_uint b)
{
	t_uint	leap_years;

	leap_years = 0;
	while (b > a)
	{
		if (ft_yearisleap(b))
			++leap_years;
		--b;
	}
	return (leap_years);
}
