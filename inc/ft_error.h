/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:02:24 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/22 19:49:45 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H
# include <errno.h>
# include <string.h>

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

int	g_errnum = 0;

int		ft_put_msg_error(char *msg, int error_flag);

#endif
