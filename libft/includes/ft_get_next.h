/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 03:10:17 by efouille          #+#    #+#             */
/*   Updated: 2019/06/04 19:34:10 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_H
# define FT_GET_NEXT_H
# define BUFF_SIZE 1024

enum			e_ret
{
	ok = 1,
	done = 0,
	fail = -1
};

typedef struct	s_gnlfile
{
	int			fd;
	char		**line;
}				t_gnlfile;

int				get_next(int fd, char **line, char sep);
int				get_next_line(int fd, char **line);

#endif
