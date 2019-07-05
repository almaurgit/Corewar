/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 19:26:35 by efouille          #+#    #+#             */
/*   Updated: 2019/03/25 15:24:47 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_const.h"
#include "lftmath.h"
#include "lftstring.h"
#include <stdlib.h>
#include <locale.h>

static void	add_separators(char **nbr, int len, t_uint base)
{
	char	sep;
	int		width;

	width = base == 2 ? 4 : 3;
	sep = base == 2 ? ' ' : ',';
	if (sep)
	{
		if (len >= width)
			len -= width;
		while (len > 0)
		{
			ft_strins(nbr, sep, len);
			len -= width;
		}
	}
}

char		*ft_utoa_base(t_umax n, const t_uint b, int caps, int s)
{
	char	*ret;
	int		len;
	int		k;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_log(n, b);
	ret = (char*)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	k = len;
	while (n > 0)
	{
		ret[--k] = caps ? BASE_CAPS[n % b] : BASE[n % b];
		n /= b;
	}
	ret[len] = '\0';
	if (s)
		add_separators(&ret, len, b);
	return (ret);
}
