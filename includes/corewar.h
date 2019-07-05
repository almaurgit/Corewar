/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 06:59:54 by efouille          #+#    #+#             */
/*   Updated: 2019/06/04 00:27:53 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "corewar_types.h"
# include "libft_types.h"
# include <ncurses.h>

/*
** op.c
*/

t_op	*ops(void);

/*
** op_gen.c
*/

t_op	op_first(char *name, int argc, t_u8 opcode, int n_cycles);
void	op_second(t_op *op, t_u8 has_ocp, t_u8 is_index, t_ins ins);
void	op_args(t_op *op, t_u8 arg0, t_u8 arg1, t_u8 arg2);

/*
** clean/players.c
*/

void	clean_players(t_corewar *c);

/*
** clean/procs.c
*/

void	clean_proc(t_corewar *c, int i);
void	clean_procs(t_corewar *c);

/*
** common/check_args.c
*/

int		invalid_args(int opcode, t_args *a);

/*
** common/increase_pc.c
*/

void	increase_pc(int *pc, int n);

/*
** common/rotate_pc.c
*/

void	rotate_pc(int *pc);

/*
** clean/clean_programs.c
*/

void	clean_corfiles(t_corewar *c);

/*
** instructions
*/

void	cw_add(t_corewar *c, int i);
void	cw_aff(t_corewar *c, int i);
void	cw_and(t_corewar *c, int i);
void	cw_fork(t_corewar *c, int i);
void	cw_ld(t_corewar *c, int i);
void	cw_ldi(t_corewar *c, int i);
void	cw_lfork(t_corewar *c, int i);
void	cw_live(t_corewar *c, int i);
void	cw_lld(t_corewar *c, int i);
void	cw_lldi(t_corewar *c, int i);
void	cw_or(t_corewar *c, int i);
void	cw_st(t_corewar *c, int i);
void	cw_sti(t_corewar *c, int i);
void	cw_sub(t_corewar *c, int i);
void	cw_xor(t_corewar *c, int i);
void	cw_zjmp(t_corewar *c, int i);

/*
** parse/parse_instructions.c
*/

int		treat_instruction(t_corewar *c, int i);

/*
** read/args.c
*/

int		read_args(t_corewar *corewar, int ac, char **av);

/*
** read/read.c
*/

int		read_cor(char *path, t_corfile **cf);

/*
** read/error.c
*/

void	error(int e, char *arg);

/*
** read/players.c
*/

int		add_player(t_corewar *c, t_corfile *cf);

/*
** run/args.c
*/

int		get_arg(t_corewar *c, int i, int arg, t_u8 reg_content);
int		get_larg(t_corewar *c, int i, int arg, t_u8 use_content);

/*
** run/execute.c
*/

void	execute(t_corewar *c, int i);

/*
** run/kill.c
*/

void	kill(t_corewar *c);

/*
** run/loop.c
*/

int		interrupt_loop(t_corewar *c);
void	run_step(t_corewar *c);
void	corewar_loop(t_corewar *c);

/*
** run/procs.c
*/

int		create_first_procs(t_corewar *c);
int		fork_proc(t_corewar *c, int p, int pc);

/*
** run/read.c
*/

void	read_mem(t_corewar *c, int src, t_u8 *bytes, int size);

/*
** run/register.c
*/

void	set_reg(t_corewar *c, int proc, int reg, int val);
void	get_reg(t_corewar *c, int proc, int reg, int *val);

/*
** run/win.c
*/

void	announce_winner(t_corewar *c);
void	tui_announce_winner(t_corewar *c);

/*
** run/write.c
*/

void	write_mem(t_corewar *c, int dst, t_u8 *bytes, int size);
void	write_owner(t_corewar *c, int dst, int player, int size);

/*
** show/dump.c
*/

void	dump(t_corewar *c, int bytes_per_line);

/*
** show/ins_verbose.c
*/

void	verbose(t_corewar *c, int i);

/*
** show/introduce.c
*/

void	introduce_contestants(t_corewar *c);

/*
** show/init_tui.c
*/

void	init_tui(t_corewar *c);
void	change_colors(void);

/*
** show/tui.c
*/

t_getch	*f_getch(void);
int		tui(t_corewar *c, t_u8 end);
void	tui_memory(t_corewar *c);

/*
**	show/tui_info.c
*/

int		tui_info(t_corewar *c, t_u8 end);

/*
** show/f_ch.c
*/

void	ft_decrease_cps(t_corewar *c);
void	ft_decrease_cps1(t_corewar *c);
void	ft_increase_cps1(t_corewar *c);
void	ft_increase_cps(t_corewar *c);
void	ft_next_cycle(t_corewar *c);

/*
** tui_space.c
*/

void	ft_space(t_corewar *c);
void	ft_max_cycles(t_corewar *c);

/*
** show/tui_procs.c
*/

void	ft_procs(t_corewar *c);
void	ft_cancel_procs(t_corewar *c);

/*
** show/tui_ins.c
*/

void	tui_ins(t_corewar *c, int i, int owner);

/*
** show/tui_help.c
*/

void	ft_help(t_corewar *c);

/*
** show/usage.c
*/

void	usage(void);

#endif
