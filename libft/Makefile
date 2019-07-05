# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efouille <efouille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/18 14:36:22 by efouille          #+#    #+#              #
#    Updated: 2019/05/21 18:39:50 by efouille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_PURPLE=\x1b[35m
_BOLD=\x1b[1m
_DEFAULT=\x1b[0m

CC=clang

override CFLAGS+=-Wall -Werror -Wextra -Iincludes

NAME=libft.a

SRC_CTYPE=ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isblankspace.c \
	ft_isdigit.c ft_ishexdigit.c ft_isnumber.c ft_isprint.c ft_isspace.c \
	ft_tolower.c ft_toupper.c

SRC_IO=ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
	ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_puttstr.c ft_putunbr.c \
	ft_putunbr_fd.c ft_putwchar_fd.c ft_putwchar.c ft_putwstr_fd.c \
	ft_putwstr.c ft_get_next.c

SRC_IO+=ft_printf_casters.c ft_printf_checkers.c ft_printf_env.c \
	ft_printf_format_list.c ft_asprintf.c ft_dprintf.c ft_printf.c \
	ft_sprintf.c ft_printf_parser.c ft_printf_ascii.c ft_printf_date.c \
	ft_printf_double.c ft_printf_int.c ft_printf_int_helpers.c \
	ft_printf_sanitizer.c ft_printf_tools.c ft_printf_xtra.c

SRC_LIB=ft_atoi.c ft_atoimax.c ft_atoumax.c ft_days_before_month.c ft_dtoa.c \
	ft_itoa.c ft_itoa_base.c ft_leap_years_between.c ft_memalloc.c \
	ft_memdel.c ft_utoa_base.c ft_realloc.c ft_xatoi.c ft_yearisleap.c

SRC_LIST=ft_lstadd.c ft_lstappend.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
	ft_lstmap.c ft_lstnew.c ft_lstdelfirst.c

SRC_MATH=ft_2_complement.c ft_abs.c ft_getbit.c ft_getfbit.c \
	ft_getfexponent.c ft_getfmantissa.c ft_getfmantissa_dec.c ft_getfsign.c \
	ft_log.c ft_matadd.c ft_matdel.c ft_matmult.c ft_matnew.c ft_matprod.c \
	ft_max.c ft_min.c ft_pow.c ft_setbit.c ft_sqrt.c ft_swapbytes.c \
	ft_unsetbit.c

SRC_STACK=ft_stknew.c ft_stkpop.c ft_stkpush.c

SRC_STRING=ft_bzero.c ft_endswith.c ft_index_of.c ft_index_of_nth.c \
	ft_nindex_of.c ft_nindex_of_nth.c \
	ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
	ft_memset.c ft_strappendchr.c ft_strappendstr.c ft_strcat.c ft_strchr.c \
	ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
	ft_strins.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strjoin_free.c \
	ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strnappendstr.c \
	ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
	ft_strnstr.c ft_strrchr.c ft_strrev.c ft_strsclr.c ft_strscpy.c \
	ft_strshift.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strsub_free.c \
	ft_strtolst.c ft_strtrim.c ft_tablen.c ft_tstrappendchr.c \
	ft_tstrappendstr.c ft_tstrdel.c ft_tstrnappendstr.c ft_tstrnew.c \
	ft_wchartostr.c

SRC_CTYPE:=$(addprefix src/lftctype/, ${SRC_CTYPE})
SRC_IO:=$(addprefix src/lftio/, ${SRC_IO})
SRC_LIB:=$(addprefix src/lftlib/, ${SRC_LIB})
SRC_LIST:=$(addprefix src/lftlist/, ${SRC_LIST})
SRC_MATH:=$(addprefix src/lftmath/, ${SRC_MATH})
SRC_STACK:=$(addprefix src/lftstack/, ${SRC_STACK})
SRC_STRING:=$(addprefix src/lftstring/, ${SRC_STRING})

SOURCE=${SRC_CTYPE}
SOURCE+=${SRC_IO}
SOURCE+=${SRC_LIB}
SOURCE+=${SRC_LIST}
SOURCE+=${SRC_MATH}
SOURCE+=${SRC_STACK}
SOURCE+=${SRC_STRING}

HEADER=libft_const.h libft_types.h lftctype.h lftio.h lftlib.h lftlist.h \
	lftmath.h lftstack.h lftstring.h \
	ft_get_next.h ft_printf.h ft_printf_private.h \
	ft_printf_const.h ft_printf_types.h ft_printf_xtra.h

HEADER:=$(addprefix includes/, ${HEADER})

OBJ=${SOURCE:.c=.o}

all: $(NAME)
	@printf "${_BOLD}${_PURPLE}[libft ok]${_DEFAULT}\n"

debug: CFLAGS += -g
debug: RULE=debug
debug: $(NAME)

asan: CFLAGS += -fsanitize=address -g
asan: RULE=asan
asan: $(NAME)

$(NAME): $(OBJ)
	@printf "${_BOLD}${_PURPLE}[   libft]${_DEFAULT} ar rcs $(NAME) $(OBJ)\n"
	@ar rcs $(NAME) $(OBJ)
	@printf "${_BOLD}${_PURPLE}[   libft]${_DEFAULT} ranlib $(NAME)\n"
	@ranlib $(NAME)

%.o: %.c $(HEADER)
	@printf "${_BOLD}${_PURPLE}[   libft]${_DEFAULT} $(CC) $(CFLAGS) -c -o $@ $<\n"
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
