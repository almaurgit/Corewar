/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_date.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 03:48:00 by efouille          #+#    #+#             */
/*   Updated: 2019/03/24 10:33:01 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include "lftlib.h"
#include "lftstring.h"

static t_date	calculate_date(t_umax timestamp)
{
	t_date	d;
	int		leap_years;

	d.years = timestamp / (60 * 60 * 24 * 365);
	leap_years = ft_leap_years_between(1970, 1970 + d.years);
	timestamp -= (d.years * 365 + leap_years) * 24 * 60 * 60;
	d.months = timestamp / (60 * 60 * 24 * 30) + 1;
	timestamp -= ft_days_before_month(d.months, d.years + 1970) * 24 * 60 * 60;
	d.days = timestamp / (60 * 60 * 24) + 1;
	timestamp -= (d.days - 1) * 24 * 60 * 60;
	d.hours = timestamp / (60 * 60) + 1;
	timestamp -= (d.hours - 1) * 60 * 60;
	d.minutes = timestamp / 60;
	timestamp -= d.minutes * 60;
	d.seconds = timestamp;
	d.years += 1970;
	return (d);
}

void			print_date(t_pfenv *env)
{
	t_umax	k;
	t_date	d;
	char	tmp[17];

	k = va_arg(env->vl, t_umax);
	d = calculate_date(k);
	tmp[0] = '0' + (d.years / 1000);
	tmp[1] = '0' + (d.years % 1000) / 100;
	tmp[2] = '0' + (d.years % 100) / 10;
	tmp[3] = '0' + (d.years % 10);
	tmp[4] = '-';
	tmp[5] = '0' + (d.months / 10);
	tmp[6] = '0' + (d.months % 10);
	tmp[7] = '-';
	tmp[8] = '0' + (d.days / 10);
	tmp[9] = '0' + (d.days % 10);
	tmp[10] = 'T';
	tmp[11] = '0' + (d.hours / 10);
	tmp[12] = '0' + (d.hours % 10);
	tmp[13] = ':';
	tmp[14] = '0' + (d.minutes / 10);
	tmp[15] = '0' + (d.minutes % 10);
	tmp[16] = '\0';
	ft_tstrappendstr(env->output, tmp);
}
