/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 00:53:28 by efouille          #+#    #+#             */
/*   Updated: 2019/03/25 15:05:21 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include "lftlib.h"
#include "lftstring.h"
#include <stdlib.h>

int		get_nbr(const char *s, int start, int end)
{
	char	*tmp;
	int		ret;

	tmp = ft_strsub(s, start, end - start);
	ret = ft_atoi(tmp);
	free(tmp);
	return (ret);
}

char	*get_str_next(const char *s, int *k)
{
	int	start;

	start = *k;
	while (s[*k] && s[*k] != '%')
		++(*k);
	return (ft_strsub(s, start, *k - start));
}

void	clean_all(t_pfenv *env)
{
	fmt_clear(&(env->formats));
	clear_env(&env);
}

void	print_nchars(t_pfenv *env, char c, int n)
{
	char	*s;
	int		k;

	if (n > 0)
	{
		s = ft_strnew(n);
		if (s)
		{
			k = -1;
			while (++k < n)
				s[k] = c;
			s[k] = '\0';
			ft_tstrappendstr(env->output, s);
			free(s);
		}
	}
}
