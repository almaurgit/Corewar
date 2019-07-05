/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lftctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 12:40:20 by efouille          #+#    #+#             */
/*   Updated: 2019/04/24 15:51:10 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFTCTYPE_H
# define LFTCTYPE_H

int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isblankspace(int c);
int			ft_isdigit(int c);
int			ft_ishexdigit(int c, int uppercase);
int			ft_isnumber(char *s);
int			ft_isprint(int c);
int			ft_isspace(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

#endif
