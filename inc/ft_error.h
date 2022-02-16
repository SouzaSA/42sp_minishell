/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:02:24 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/16 10:35:11 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include "libft.h"
# include "ft_base_macros.h"

# define FLAG_ERROR_P 0
# define FLAG_ERROR_STR 1
# define FLAG_ERROR_OWN 2

# define EXIT_SHELL_SUCCESS 0
# define EXIT_SHELL_ERROR_GENERIC 1
# define EXIT_SHELL_ERROR_MISSUSE_BUITIN 2
# define EXIT_SHELL_ERROR_CANNOT_EXECUTE 126
# define EXIT_SHELL_ERROR_CMD_NOT_FOUND 127
# define EXIT_SHELL_ERROR_INVALID_ARG_TO_EXIT 128
# define EXIT_SHELL_ERROR_SIGNAL_N 128

# define ENOENT 2
# define ENOMEM 12
# define ENOTDIR 20
# define ENODATA 61

extern int	g_errnum;

int		ft_put_msg_error(char *msg, int error_flag);
void	ft_parser_error_msg(char *tok_text);
#endif
