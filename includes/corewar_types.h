/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 06:57:27 by efouille          #+#    #+#             */
/*   Updated: 2019/05/22 19:22:44 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_TYPES_H
# define COREWAR_TYPES_H

# include "corewar_const.h"
# include "libft_types.h"
# include <ncurses.h>

typedef struct	s_header
{
	t_uint	magic;
	char	prog_name[PROG_NAME_LENGTH + 1];
	t_uint	prog_size;
	char	comment[COMMENT_LENGTH + 1];
}				t_header;

typedef struct	s_corfile
{
	t_header	header;
	t_u8		*program;
}				t_corfile;

typedef struct	s_args
{
	int		argc;
	int		*args;
	t_u8	*argt;
}				t_args;

typedef struct	s_exec
{
	int		remaining_cycles;
	t_u8	opcode;
	t_args	*a;
	t_u8	done;
}				t_exec;

typedef struct	s_process
{
	int		player;
	int		*reg;
	int		pc;
	int		delta_pc;
	t_u8	carry;
	t_exec	*exec;
	t_u8	execed_this_cycle;
	t_u8	waiting;
	t_u8	living;
}				t_process;

typedef struct	s_player
{
	t_corfile	*file;
	int			number;
	char		*name;
	int			last_live;
}				t_player;

typedef struct	s_corewar
{
	t_player	**players;
	int			nplayers;
	t_process	**procs;
	int			nprocs;
	int			nliving;
	t_u8		mem[MEM_SIZE];
	t_i8		owner[MEM_SIZE];
	t_i8		pc[MEM_SIZE];
	int			cycles;
	int			cycles_to_die;
	int			nb_checks;
	int			checks;
	int			next_kill;
	int			total_live;
	t_u8		verbose;
	int			dump;
	int			dump_size;
	t_u8		flagnumber;
	int			number_next_player;
	t_u8		tui;
	int			tui_timeout;
	int			tui_proc0;
	int			cycles_per_s;
	t_u8		tui_pause;
	t_u8		tui_help;
	t_u8		show_aff;
}				t_corewar;

typedef void	(*t_ins)(t_corewar*, int);

typedef struct	s_op
{
	char	*name;
	int		argc;
	t_u8	arg_types[4];
	t_u8	opcode;
	int		n_cycles;
	t_u8	has_ocp;
	t_u8	is_index;
	t_ins	ins;
}				t_op;

typedef	struct	s_getch
{
	int		ch;
	void	(*f_ch)(t_corewar *c);
}				t_getch;

enum			e_cw_error
{
	cw_header_error = -9,
	cw_overlap_champs,
	cw_number_error,
	cw_magic_error,
	cw_size_error,
	cw_malloc_error,
	cw_open_error,
	cw_no_programs,
	cw_no_first_procs
};

#endif
