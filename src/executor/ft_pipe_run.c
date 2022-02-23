/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:00:26 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/22 11:05:06 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

int	ft_pipe_run(t_cmd_data *cmd_data)
{
	int	rtn;

	rtn = 0;
	waitpid(cmd_data->pid, NULL, 0);
	if (cmd_data->fd_out == 1)
		dup2(cmd_data->pipe_fd[0], 0);
	else if (cmd_data->fd_out > 1)
		close(cmd_data->fd_out);
	close(cmd_data->pipe_fd[0]);
	return (rtn);
}
