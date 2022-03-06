# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 08:50:14 by sde-alva          #+#    #+#              #
#    Updated: 2022/03/06 15:31:00 by edpaulin         ###   ########.fr        #
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
					${EXECUTOR_ADD_DIR} \
					${UTILS_ADD_DIR}	\
					${SCANNER_ADD_DIR}	\
					${TAPE_SOURCE_ADD_DIR} \
					${SIG_ADD_DIR} \
					${EXPAND_ADD_DIR} \
					${PROMPT_ADD_DIR}

BUILTINS		=	ft_builtins_parser.c	\
					ft_cd.c	\
					ft_echo.c	\
					ft_env.c \
					ft_exit.c \
					ft_export.c	\
					ft_export_utils.c	\
					ft_isbuiltin.c	\
					ft_pwd.c	\
					ft_unset.c

ERROR			=	ft_cd_errors.c	\
					ft_command_error.c	\
					ft_export_error.c	\
					ft_heredoc_error.c	\
					ft_put_msg_error.c	\
					ft_parser_error_msg.c	\
					ft_unset_error.c

EXECUTOR		=	ft_and_or_run.c	\
					ft_builtin_run.c	\
					ft_checker_slash.c	\
					ft_cmd_assignments.c	\
					ft_cmd_redirections.c	\
					ft_cmd_run.c	\
					ft_construct_envp.c	\
					ft_construct_path.c	\
					ft_executor.c	\
					ft_get_cmd_path.c	\
					ft_here_doc.c	\
					ft_pipe_run.c

PARSER			=	ft_child_node.c	\
					ft_free_node_tree.c	\
					ft_new_node.c	\
					ft_parser.c	\
					ft_set_node_val_str.c	\
					ft_syntax.c	\
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
					ft_pipeline.c	\
					ft_redirect_list.c	\
					ft_simple_cmd.c	\
					ft_start.c	\
					ft_stk_add_child.c	\
					ft_stk_node.c	\
					ft_stk_set_node.c	\
					ft_subshell.c

PROMPT			=	ft_get_prompt.c

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

UTILS			=	ft_destroy_ast_stk.c	\
					ft_destroy_ast.c	\
					ft_destroy_cmd_struct.c	\
					ft_destroy_dictionary_element.c	\
					ft_destroy_dictionary_list.c	\
					ft_destroy_shell.c	\
					ft_destroy_tt.c	\
					ft_get_env_node_by_key.c	\
					ft_get_env_value_by_key.c	\
					ft_get_local_var_by_key.c	\
					ft_init_vars.c	\
					ft_isidentifier.c	\
					ft_split_join.c	\
					ft_update_env_pwd.c

EXPAND			=	ft_expand_star.c \
					ft_get_splitted_path.c \
					ft_clean_file_struct.c \
					ft_del_content.c \
					ft_expand_exit_num.c	\
					ft_add_expansion_to_list.c \
					ft_match_star.c \
					ft_expand_tild.c	\
					ft_expand_vars.c	\
					ft_is_dot_dir.c \
					ft_pathcat.c \
					ft_is_dir.c \
					ft_expand_list.c

SIG				=	ft_handle_prompt_signals.c \
					ft_handle_child_process_signals.c \
					ft_handle_parent_process_signals.c

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
SIG_ADD_DIR	=		${addprefix ${SIG_DIR}/,${SIG}}
EXPAND_ADD_DIR	=	${addprefix ${EXPAND_DIR}/,${EXPAND}}

RM				=	@rm -rf

DIR_GUARD		=	@mkdir -p $@

${OBJ_DIR}/.:
					${DIR_GUARD}

${OBJ_DIR}%/.:
					${DIR_GUARD}

.SECONDEXPANSION:

${OBJ_DIR}/%.o:	${SRC_DIR}/%.c | $${@D}/.
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

.PRECIOUS:		${OBJ_DIR}/. ${OBJ_DIR}%/.