/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:00:26 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/13 18:59:55 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

int	ft_pipe_run(t_cmd_data *data, t_list *cmd_stk)
{
	int	rtn;
	int	wstatus;

	rtn = 0;
	if (cmd_stk && ft_lstsize(cmd_stk) \
		&& (((t_ast *)cmd_stk->content)->type != AST_AND \
		|| ((t_ast *)cmd_stk->content)->type != AST_OR))
	{
		waitpid(data->pid, NULL, WNOHANG);
	}
	else
	{
		wait(&wstatus);
		if (!WIFSIGNALED(wstatus))
			g_exit_status = WEXITSTATUS(wstatus);
	}
	if (data->fd_out == 1)
		dup2(data->pipe_fd[0], 0);
	else if (data->fd_out > 1)
		close(data->fd_out);
	close(data->pipe_fd[0]);
	return (rtn);
}
