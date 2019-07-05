# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efouille <efouille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/18 14:36:22 by efouille          #+#    #+#              #
#    Updated: 2019/06/05 21:11:18 by lduqueno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_PURPLE=\x1b[31m
_GREEN=\x1b[32m
_BOLD=\x1b[1m
_DEFAULT=\x1b[0m

CC=clang

MAKE=make

RM=rm

override CFLAGS+=-Wall -Werror -Wextra -Iincludes -Ilibft/includes

override LDFLAGS+=-Llibft -lft -lncurses

NAME=corewar42
NAME_ASM=asm
NAME_COREWAR=corewar

SOURCE_ASM=data/instru.c \
			data/label.c \
			data/op.c \
			data/set_op.c \
			misc/arguments.c \
			misc/error.c \
			misc/free.c \
			parser/parser_header.c \
			parser/parser_instructions.c \
			parser/parser_labels.c \
			parser/parser.c \
			writer/pc.c \
			writer/write_args.c \
			writer/write.c \
			asm.c
SOURCE_ASM:=$(addprefix src/asm/, ${SOURCE_ASM})

SOURCE_COREWAR=corewar.c \
				op.c \
				op_gen.c \
				clean/players.c \
				clean/procs.c \
				common/check_args.c \
				common/increase_pc.c \
				common/rotate_pc.c \
				instructions/add.c \
				instructions/aff.c \
				instructions/and.c \
				instructions/fork.c \
				instructions/ld.c \
				instructions/ldi.c \
				instructions/lfork.c \
				instructions/live.c \
				instructions/lld.c \
				instructions/lldi.c \
				instructions/or.c \
				instructions/st.c \
				instructions/sti.c \
				instructions/sub.c \
				instructions/xor.c \
				instructions/zjmp.c \
				parse/parse_instructions.c \
				read/args.c \
				read/read.c \
				read/error.c \
				read/players.c \
				run/args.c \
				run/execute.c \
				run/kill.c \
				run/loop.c \
				run/procs.c \
				run/read.c \
				run/register.c \
				run/win.c \
				run/write.c \
				show/dump.c \
				show/ins_verbose.c \
				show/introduce.c \
				show/init_tui.c \
				show/tui.c \
				show/tui_info.c \
				show/f_ch.c \
				show/tui_space.c \
				show/tui_procs.c \
				show/tui_ins.c \
				show/tui_help.c \
				show/usage.c
SOURCE_COREWAR:=$(addprefix src/corewar/, ${SOURCE_COREWAR})

HEADER=corewar.h corewar_const.h corewar_types.h asm.h op.h
HEADER:=$(addprefix includes/, ${HEADER})

LIBS=libft/libft.a

OBJ_ASM=${SOURCE_ASM:.c=.o}
OBJ_COREWAR=${SOURCE_COREWAR:.c=.o}

.PHONY: all $(NAME) libft clean fclean re champ clean_champ

all: $(NAME)
	@printf "${_BOLD}${_GREEN}Created executables $(NAME_ASM) and $(NAME_COREWAR) ${_DEFAULT}\n"

$(NAME): $(NAME_ASM) $(NAME_COREWAR)

$(NAME_ASM): $(LIBS) $(OBJ_ASM)
	@printf "${_BOLD}${_GREEN}[     asm]${_DEFAULT} $(CC) $(CFLAGS) $(OBJ_ASM) -o $(NAME_ASM) $(LDFLAGS)\n"
	@$(CC) $(CFLAGS) $(OBJ_ASM) -o $(NAME_ASM) $(LDFLAGS)
	@printf "${_BOLD}${_GREEN}[  asm ok]${_DEFAULT}\n"

$(NAME_COREWAR): $(LIBS) $(OBJ_COREWAR)
	@printf "${_BOLD}${_GREEN}[      vm]${_DEFAULT} $(CC) $(CFLAGS) $(OBJ_COREWAR) -o $(NAME_COREWAR) $(LDFLAGS)\n"
	@$(CC) $(CFLAGS) $(OBJ_COREWAR) -o $(NAME_COREWAR) $(LDFLAGS)
	@printf "${_BOLD}${_GREEN}[   vm ok]${_DEFAULT}\n"

%.o: %.c $(HEADER)
	@printf "${_BOLD}${_GREEN}[ corewar]${_DEFAULT} $(CC) $(CFLAGS) -c $< -o $@\n"
	@$(CC) $(CFLAGS) -c $< -o $@

libft: libft/libft.a

libft/libft.a:
	@printf "${_BOLD}${_GREEN}[   libft]${_DEFAULT} $(MAKE) -C libft $(RULE)\n"
	@$(MAKE) -C libft $(RULE)

clean:
	@$(RM) -f $(OBJ_ASM) $(OBJ_COREWAR)
	@$(MAKE) -C libft clean

fclean: clean
	@$(RM) -f $(NAME_ASM) $(NAME_COREWAR)
	@$(RM) -rf $(NAME_ASM).dSYM $(NAME_COREWAR).dSYM
	@$(MAKE) -C libft fclean
	@printf "Project entirely cleared\n"

re: fclean all

champ: bedrock.cor

bedrock.cor: bedrock.s $(NAME_ASM)
	@printf "${_BOLD}${_PURPLE}[   champ]${_DEFAULT} ./$(NAME_ASM) bedrock.s\n"
	@./$(NAME_ASM) bedrock.s

clean_champ:
	@printf "${_BOLD}${_PURPLE}[   champ]${_DEFAULT} $(RM) bedrock.cor\n"
	@$(RM) bedrock.cor
