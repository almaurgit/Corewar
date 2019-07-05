/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xtra.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 03:16:38 by efouille          #+#    #+#             */
/*   Updated: 2019/03/23 07:46:10 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_XTRA_H
# define FT_PRINTF_XTRA_H

# define PRINTF_XTRA_GET 1
# define PRINTF_XTRA_SET 2

/*
** ==== XTRA FUNCTION ====
**
** This function allows the user to add custom conversions to ft_printf
*/

t_printer	ft_printf_xtra_printer(char c, t_printer p, int mode);
int			improve_ftprintf(char c, t_printer p);

/*
** ==== SAMPLE XTRA USAGE ====
**
** #include "ft_printf.h"
** #include "ft_printf_types.h"
** #include "ft_printf_xtra.h"
**
** void	k_print(t_pfenv *env)
** {
** 	int	k;
**
** 	k = va_arg(env->vl, int);
** 	while (--k >= 0)
** 		ft_tstrappendchr(env->output, 'K');
** }
**
** a printf must get its argument from va_list.
** it will always happen in the right order, just use va_arg and pass
** the vl from environment then the type you want to use.
** the environment cur_fmt (env->cur_fmt) contains all field width, padding,
** flags ... informations you may need.
** To print the result :
**     use ft_tstrappendchr to add one char
**     use ft_tstrappendstr to add one whole string
**
** int	main(void)
** {
** 	init_xtra();
** 	improve_ftprintf('k', k_print);
** 	ft_printf("I'm printing %d times K with my %%k : %k\n", 10, 10);
** 	clean_xtra();
** 	return (0);
** }
**
** init_xtra will initilize xtra globals
** improve_ftprintf adds the new printer
** clean_xtra frees globals
*/

#endif
