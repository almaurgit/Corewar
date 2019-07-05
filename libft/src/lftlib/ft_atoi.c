/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 00:35:11 by Edgar             #+#    #+#             */
/*   Updated: 2019/06/04 17:20:44 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_types.h"
#include "lftctype.h"

static void	loop(const char *str, long i, t_ull *nbr, long negative)
{
	int	cond;

	cond = *nbr <= 9223372036854775807ULL && negative == 1;
	cond += *nbr <= 9223372036854775808ULL && negative == -1;
	cond = cond && str[i] && str[i] >= '0' && str[i] <= '9';
	while (cond)
	{
		*nbr = 10 * *nbr + (long)str[i++] - '0';
		cond = *nbr <= 9223372036854775807ULL && negative == 1;
		cond += *nbr <= 9223372036854775808ULL && negative == -1;
		cond = cond && str[i] && str[i] >= '0' && str[i] <= '9';
	}
}

int			ft_atoi(const char *str)
{
	long	i;
	t_ull	nbr;
	long	negative;

	nbr = 0;
	negative = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		negative = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	loop(str, i, &nbr, negative);
	if (nbr > 9223372036854775807ULL && negative == 1)
		return (-1);
	if (nbr > 9223372036854775808ULL && negative == -1)
		return (0);
	return ((int)negative * (int)nbr);
}
