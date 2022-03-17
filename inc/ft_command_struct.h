/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_struct.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:07:49 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/16 22:13:37 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMMAND_STRUCT_H
# define FT_COMMAND_STRUCT_H

# include "libft.h"

typedef struct s_cmd_data
{
	char		**cmd;
	int			fd_in;
	int			fd_out;
	int			builtin_flag;
	int			pipe_flag;
	int			pipe_fd[2];
	int			forked;
	int			last_status;
	int			pid;
	t_cmd_blk	*blk;
	t_list		**cmd_stk;
}	t_cmd_data;

#endif
