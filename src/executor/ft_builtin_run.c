/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_run.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:40:18 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/06 16:05:59 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

static int	ft_child(t_shell *shell, t_cmd_data *data, t_cmd_blk *cmd);
static int	ft_forker_builtin(t_shell *shell, t_cmd_data *data, t_cmd_blk *blk);
static int	ft_exec_builtin(t_shell *shell, t_cmd_data *data, t_cmd_blk *blk);

int	ft_builtin_run(t_shell *shell, t_cmd_data *data, t_ast *ast)
{
	int			rtn;
	t_cmd_blk	*blk;

	rtn = 0;
	blk = ast->blk;
	free(ast);
	data->cmd = NULL;
	data->fd_in = 0;
	data->fd_out = 1;
	data->pid = -1;
	rtn = ft_assignments(shell, blk->assign);
	rtn = ft_redirections(shell, blk->redir, &data->fd_in, &data->fd_out);
	rtn = ft_forker_builtin(shell, data, blk);
	if (data->cmd)
		free(data->cmd);
	ft_destroy_command(&blk);
	return (rtn);
}

static int	ft_forker_builtin(t_shell *shell, t_cmd_data *data, t_cmd_blk *cmd)
{
	int	rtn;

	rtn = 0;
	if (pipe(data->pipe_fd) == -1)
		rtn = ft_put_msg_error(NULL, FLAG_ERROR_P);
	data->pid = fork();
	if (data->pid == -1)
		rtn = ft_put_msg_error(NULL, FLAG_ERROR_P);
	if (rtn == 0 && data->pid == 0)
		rtn = ft_child(shell, data, cmd);
	waitpid(-1, NULL, WNOHANG);
	close(data->pipe_fd[1]);
	return (rtn);
}

static int	ft_child(t_shell *shell, t_cmd_data *data, t_cmd_blk *cmd)
{
	int	rtn;

	rtn = 0;
	ft_destroy_tt(&shell->transition_table);
	rl_clear_history();
	ft_destroy_ast_stk(data->cmd_stk);
	if (data->fd_in >= 0 && data->fd_out > 0)
		rtn = ft_exec_builtin(shell, data, cmd);
	else
	{
		close(data->pipe_fd[0]);
		close(data->pipe_fd[1]);
		ft_destroy_command(&cmd);
		ft_destroy_shell(shell);
		if (data->fd_in < 0 || data->fd_out < 0)
			exit(1);
		else
			exit(0);
	}
	ft_handle_parent_process_signals();
	waitpid(-1, NULL, WNOHANG);
	close(data->pipe_fd[1]);
	return (rtn);
}

static int	ft_exec_builtin(t_shell *shell, t_cmd_data *data, t_cmd_blk *cmd)
{
	int	rtn;

	rtn = 0;
	close(data->pipe_fd[0]);
	ft_pipe_worker(data);
	rtn = ft_builin_parser(shell, data, cmd);
	ft_destroy_command(&cmd);
	ft_destroy_shell(shell);
	exit(rtn);
}
