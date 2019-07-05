/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:01:17 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/08 14:48:30 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"

# define DEBUG_ARG_1			"--debug"
# define DEBUG_ARG_2			"-d"
# define PATH_ARG_1				"--path"
# define PATH_ARG_2				"-p"
# define OP_COUNT				16
# define REGISTER_CHAR			'r'
# define REG_WRITE_SIZE			1
# define IND_WRITE_SIZE			2
# define DIR_WRITE_SIZE			4

# define USAGE_ERROR			"Usage: ./asm (--debug | -d) (--path | -p) file"
# define MALLOC_ERROR			"Memory allocation failed"
# define PARSE_ERROR			"At line #%d"
# define PARSE_ERROR_LINE		"At line #%d ('%s')"
# define FILE_ERROR				"This file doesn't exists"
# define READ_ERROR				"Unable to read this file"
# define NO_NAME_ERROR			"Missing .name"
# define NO_COMMENT_ERROR		"Missing .comment"
# define NO_INSTRUS_ERROR		"There is no instructions or labels"
# define BAD_TYPE_ERROR			"Bad argument type"
# define ARG_NOT_NUMBER_ERROR	"The arg value is not a number or label"
# define ARG_LABEL_NULL_ERROR	"This label doesn't exists"
# define BAD_REGISTER_ERROR		"The register value is too high or low"
# define MISSING_QUOTE_ERROR	"Missing quote in the name or comment"
# define BAD_CHARACTER_ERROR	"Found bad character"
# define BAD_SEPARATOR_ERROR	"Bad argument separator"
# define BAD_INSTRUCTION_ERROR	"This instruction does not exists"
# define BAD_SYNTAX_ERROR		"Bad syntax found"
# define BAD_NUMBER_ARGS_ERROR	"Bad number of arguments"
# define BAD_LABEL_NAME_ERROR	"Bad character in label name"
# define DUPLICATE_LABEL_ERROR	"Found duplicate label name"
# define DUPLICATE_NAME_ERROR	"Found duplicate .name"
# define DUPLICATE_COM_ERROR	"Found duplicate .comment"
# define BAD_NAME_COMMENT		"Bad syntax of .name or .comment"
# define NAME_TOO_LONG_ERROR	".name is too long"
# define COMMENT_TOO_LONG_ERROR	".comment is too long"
# define WRITE_ERROR			"Unable to write the binary file"
# define BAD_TOKEN_AFTER_NAME	"Bad token after name or comment"
# define STRING_TRIM_ERROR		"Unable to trim a string"

typedef struct		s_arg_code
{
	unsigned int	left : 2;
	unsigned int	arg2 : 2;
	unsigned int	arg1 : 2;
	unsigned int	arg0 : 2;
}					t_arg_code;

typedef struct		s_data
{
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	char			*input_file;
	char			*out_file;
	unsigned int	parse_line_number;
	unsigned int	nb_instructions;
	struct s_label	*labels;
	struct s_instru	*instrus;
	t_op			*ops_table;
	int				index_name_comment;
	char			wait_quotes_state;
	char			found_name;
	char			found_comment;
}					t_data;

typedef struct		s_label
{
	char			*name;
	unsigned int	pc;
	struct s_label	*left;
	struct s_label	*right;
}					t_label;

typedef struct		s_instru
{
	t_op			*op;
	char			**args;
	unsigned int	size_instru;
	struct s_instru	*next;
}					t_instru;

void				init_ops(t_data *data);

int					error(t_data *data, char *error_msg);
int					error_parse_line(t_data *data, char *error, char **line);
int					error_args(t_data *data, t_instru *instru, char *error);

int					parse(t_data *data, char debug_mode);
int					append_name_comment(t_data *data, char **line, char type);
int					retrieve_name_comment(t_data *data, char **line,
						char *raw_line);
char				*parse_next_label(t_data *data, char **line);
int					parse_next_instru(t_data *data, char **line);
int					trim_and_remove_comments(t_data *data, char **str);

t_label				*get_label_by_name(t_data *data, char *name);
int					create_label(t_data *data, char *name);
int					create_instru(t_data *data, t_op *op, char **args);
int					check_instrus_validity(t_data *data);
t_arg_type			get_arg_type(char *arg);
unsigned int		get_arg_code(char *arg);

void				free_all(t_data *data);
void				free_array(char **tab);
char				*try_malloc(t_data *data, char *malloc, char **to_free);

t_op				*get_op_by_name(t_data *data, char *name);

unsigned int		get_pc_after(t_data *data, t_instru *last);
unsigned int		get_pc_instru(t_data *data, t_instru *stop);

char				is_path_arg(char *arg);
char				is_debug_arg(char *arg);
char				read_arguments(int ac, char **av, char *debug, char *path);
void				write_debug(t_data *data);

int					write_all(t_data *data, char debug_mode);
void				write_args(t_data *data, int fd, t_instru *instru);

void				op_args(t_op *op, char arg0, char arg1, char arg2);
void				op_second(t_op *op, int encoding_byte, int dir_size);
t_op				op_first(char *name, int argc, int id);

#endif
