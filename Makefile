# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 08:50:14 by sde-alva          #+#    #+#              #
#    Updated: 2022/02/02 11:59:00 by edpaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL	:=	all

NAME			=	minishell

INC_DIR			=	inc
OBJ_DIR			=	obj
SRC_DIR			=	src
BUILTINS_DIR	=	builtins
ERROR_DIR		=	error
EXECUTOR_DIR	=	executor
PARSER_DIR		=	parser
PROMPT_DIR		=	prompt
SCANNER_DIR		=	scanner
TAPE_SOURCE_DIR	=	tape_source
UTILS_DIR		=	utils
SIG_DIR			=	signals
LL1_RULES_DIR	=	ll1_rules
EXPAND_DIR		=	expand

LIBFT			=	ft
LIBFT_DIR		=	libft
LIBFT_INC		=	${LIBFT_DIR}/inc
LIBFT_LIB		=	${LIBFT_DIR}/lib

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g
INCS			=	-I ${INC_DIR} -I ${LIBFT_INC}
LIBS			=	-L ${LIBFT_LIB} -l ${LIBFT} -lreadline -lncurses
SAN				=	-g -fsanitize=address

SRCS			=	ft_main.c	\
					ft_minishell.c	\
					${BUILTIN_ADD_DIR}	\
					${ERROR_ADD_DIR} \
					${PARSER_ADD_DIR} \
					${UTILS_ADD_DIR}	\
					${SCANNER_ADD_DIR}	\
					${TAPE_SOURCE_ADD_DIR} \
					${SIG_ADD_DIR} \
					${EXPAND_ADD_DIR}

BUILTINS		=	ft_cd.c	\
					ft_env.c \
					ft_export.c	\
					ft_pwd.c	\
					ft_unset.c

ERROR			=	ft_put_msg_error.c

EXECUTOR		=	ft_checker_slash.c	\
					ft_exec_simple_cmd.c	\
					ft_execute_command.c	\
					ft_get_cmd_path.c	\
					ft_get_path.c

PARSER			=	ft_child_node.c	\
					ft_free_node_tree.c	\
					ft_new_node.c	\
					ft_parser.c	\
					ft_set_node_val_str.c	\
					${LL1_RULES_ADD_DIR}

LL1_RULES		=	ft_and_or.c	\
					ft_cmd_prefix.c	\
					ft_cmd_sulfix.c	\
					ft_command.c	\
					ft_epslon.c	\
					ft_init_transition_table.c	\
					ft_init_transition_table1.c	\
					ft_io_file.c	\
					ft_io_here.c	\
					ft_io_redirect.c	\
					ft_new_symbol_node.c	\
					ft_pipeline.c	\
					ft_redirect_list.c	\
					ft_simple_cmd.c	\
					ft_start.c	\
					ft_subshell.c

PROMPT			=

SCANNER			=	ft_add_to_buff.c	\
					ft_del_token.c	\
					ft_init_token.c	\
					ft_lexer.c	\
					ft_set_token.c	\
					ft_tokenize.c

TAPE_SOURCE		=	ft_next_char.c	\
					ft_peek_char.c	\
					ft_skip_white_spaces_char.c	\
					ft_unget_char.c

UTILS			=	ft_destroy_dictionary_element.c	\
					ft_destroy_vars.c	\
					ft_get_env_node_by_key.c	\
					ft_get_env_value_by_key.c	\
					ft_init_vars.c	\
					ft_update_env_pwd.c

EXPAND			=	ft_expand_star.c

SIG				=	ft_handle_signals.c

BONUS			=

OBJS			=	${addprefix ./${OBJ_DIR}/,${SRCS:.c=.o}}

BONUS_OBJS		=	${addprefix ./${OBJ_DIR}/,${BONUS:.c=.o}}

UTILS_ADD_DIR	=	${addprefix ${UTILS_DIR}/,${UTILS}}

BUILTIN_ADD_DIR	=	${addprefix ${BUILTINS_DIR}/,${BUILTINS}}

ERROR_ADD_DIR	=	${addprefix ${ERROR_DIR}/,${ERROR}}

EXECUTOR_ADD_DIR	=	${addprefix ${EXECUTOR_DIR}/,${EXECUTOR}}

PARSER_ADD_DIR	=	${addprefix ${PARSER_DIR}/,${PARSER}}

LL1_RULES_ADD_DIR	=	${addprefix ${LL1_RULES_DIR}/,${LL1_RULES}}

PROMPT_ADD_DIR	=	${addprefix ${PROMPT_DIR}/,${PROMPT}}

SCANNER_ADD_DIR	=	${addprefix ${SCANNER_DIR}/,${SCANNER}}

TAPE_SOURCE_ADD_DIR	=	${addprefix ${TAPE_SOURCE_DIR}/,${TAPE_SOURCE}}

UTILS_ADD_DIR	=	${addprefix ${UTILS_DIR}/,${UTILS}}

SIG_ADD_DIR	=	${addprefix ${SIG_DIR}/,${SIG}}

EXPAND_ADD_DIR	=	${addprefix ${EXPAND_DIR}/,${EXPAND}}

RM				=	@rm -rf

DIR_GUARD		=	@mkdir -p ${@D}

${OBJ_DIR}/%.o:	${SRC_DIR}/%.c
				${DIR_GUARD}
				${CC} ${CFLAGS} ${INCS} -c $< -o $@

${NAME}:		${OBJS}
				make -C ${LIBFT_DIR}
				${CC} ${CFLAGS} ${OBJS} ${LIBS} ${INCS} -o ${NAME}

${NAME_BONUS}:	${BONUS_OBJS}
				make -C ${LIBFT_DIR}
				${CC} ${CFLAGS} ${BONUS_OBJS} ${LIBS} ${INCS} -o ${NAME_BONUS}

all:			${NAME}

bonus:			${NAME_BONUS}

san:			${OBJS}
				${CC} ${SAN} ${CFLAGS} ${OBJS} ${LIBS} ${INCS} -o ${NAME}

bonus_san:		${BONUS_OBJS}
				${CC} ${SAN} ${CFLAGS} ${BONUS_OBJS} ${LIBS} ${INCS} -o ${NAME}

clean:
				${RM} ${OBJ_DIR}
				make -C ${LIBFT_DIR} clean

fclean: 		clean
				${RM} ${NAME}
				make -C ${LIBFT_DIR} fclean

re:				fclean all

.PHONY:			all bonus san clean fclean re
