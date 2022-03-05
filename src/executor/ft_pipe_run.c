/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:00:26 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/05 12:10:03 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

int	ft_pipe_run(t_cmd_data *data)
{
	int	rtn;

	rtn = 0;
	waitpid(data->pid, NULL, WNOHANG);
	if (data->fd_out == 1)
		dup2(data->pipe_fd[0], 0);
	else if (data->fd_out > 1)
		close(data->fd_out);
	close(data->pipe_fd[0]);
	return (rtn);
}
