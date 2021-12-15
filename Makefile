# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 08:50:14 by sde-alva          #+#    #+#              #
#    Updated: 2021/12/15 20:22:51 by sde-alva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL	:=	all

NAME			=	minishell

SRC_DIR			=	src
OBJ_DIR			=	obj
INC_DIR			=	inc

LIBFT			=	ft
LIBFT_DIR		=	libft
LIBFT_INC		=	${LIBFT_DIR}/inc
LIBFT_LIB		=	${LIBFT_DIR}/lib

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
INCS			=	-I ${INC_DIR} -I ${LIBFT_INC}
LIBS			=	-L ${LIBFT_LIB} -l ${LIBFT} -lreadline
SAN				=	-g -fsanitize=address

SRCS			=	ft_get_path.c	\
					ft_main.c	\
					ft_minishell.c

BONUS			=

OBJS			=	${addprefix ./${OBJ_DIR}/,${SRCS:.c=.o}}

BONUS_OBJS		=	${addprefix ./${OBJ_DIR}/,${BONUS:.c=.o}}

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
