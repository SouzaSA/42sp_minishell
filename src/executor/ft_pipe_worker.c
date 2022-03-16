/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_worker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:29:10 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/15 20:48:39 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

void	ft_pipe_worker(t_cmd_data *data)
{
	if (data->fd_in > 0)
	{
		dup2(data->fd_in, 0);
		close(data->fd_in);
		data->fd_in = 0;
	}
	if (!data->pipe_flag)
		close(data->pipe_fd[0]);
	if (data->fd_out == 1 && data->pipe_flag)
		dup2(data->pipe_fd[1], 1);
	else if (data->fd_out > 1)
		dup2(data->fd_out, 1);
	close(data->pipe_fd[1]);
}
