/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_run.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:40:18 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/23 19:57:20 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

static int	ft_exec_cd_builtin(t_shell *shell, t_command *cmd);
static int	ft_forker_builtin(t_shell *shell, t_cmd_data *cmd_data, t_command *cmd);
static int	ft_exec_builtin(t_shell *shell, t_cmd_data *cmd_data, t_command *cmd);
static void	ft_pipe_worker(t_cmd_data *cmd_data);

int	ft_builtin_run(t_shell *shell, t_cmd_data *cmd_data, t_ast *ast)
{
	int			rtn;
	t_command	*cmd;

	rtn = 0;
	cmd = ast->cmd;
	free(ast);
	cmd_data->cmd = NULL;
	cmd_data->fd_in = 0;
	cmd_data->fd_out = 1;
	cmd_data->pid = -1;
	rtn = ft_assignments(shell, cmd->assign); // TODO CLEAN and print error msg
	rtn = ft_redirections(cmd->redir, &cmd_data->fd_in, &cmd_data->fd_out);
	if (cmd->cmd && cmd->cmd->content && !ft_strcmp((char *)(cmd->cmd->content), "cd"))
		rtn = ft_exec_cd_builtin(shell, cmd);
	else
		rtn = ft_forker_builtin(shell, cmd_data, cmd);
	if (cmd_data->cmd)
		free(cmd_data->cmd);
	ft_destroy_command(&cmd);
	return (rtn);
}

static int	ft_exec_cd_builtin(t_shell *shell, t_command *cmd)
{
	int	rtn;

	rtn = 0;
	ft_cd(shell, cmd->cmd);
	ft_lstclear(&cmd->cmd, &free);
	return (rtn);
}

static int	ft_forker_builtin(t_shell *shell, t_cmd_data *cmd_data, t_command *cmd)
{
	int	rtn;

	rtn = 0;
	if (pipe(cmd_data->pipe_fd) == -1)
		rtn = ft_put_msg_error(NULL, FLAG_ERROR_P);
	cmd_data->pid = fork();
	if (cmd_data->pid == -1)
		rtn = ft_put_msg_error(NULL, FLAG_ERROR_P);
	if (rtn == 0 && cmd_data->pid == 0)
	{
		if (cmd_data->fd_in >= 0 && cmd_data->fd_out > 0)
			rtn = ft_exec_builtin(shell, cmd_data, cmd);
		else
		{
			close(cmd_data->pipe_fd[0]);
			close(cmd_data->pipe_fd[1]);
			ft_destroy_ast_stk(cmd_data->cmd_stk);
			ft_destroy_command(&cmd);
			rl_clear_history();
			ft_destroy_shell(shell);
			if (cmd_data->fd_in < 0 &&cmd_data->fd_out < 0)
				exit(1);
			else
				exit(0);
		}
	}
	waitpid(-1, NULL, WNOHANG);
	close(cmd_data->pipe_fd[1]);
	return (rtn);
}

static int	ft_exec_builtin(t_shell *shell, t_cmd_data *cmd_data, t_command *cmd)
{
	int	rtn;

	rtn = 0;
	close(cmd_data->pipe_fd[0]);
	ft_pipe_worker(cmd_data);
	rtn = ft_builin_parser(shell, cmd);
	ft_destroy_ast_stk(cmd_data->cmd_stk);
	ft_destroy_command(&cmd);
	rl_clear_history();
	ft_destroy_shell(shell);
	exit(rtn);
}

static void	ft_pipe_worker(t_cmd_data *cmd_data)
{
	if (cmd_data->fd_in > 0)
	{
		dup2(cmd_data->fd_in, 0);
		close(cmd_data->fd_in);
		cmd_data->fd_in = 0;
	}
	if (cmd_data->fd_out == 1 && cmd_data->pipe_flag)
		dup2(cmd_data->pipe_fd[1], 1);
	else if (cmd_data->fd_out > 1)
		dup2(cmd_data->fd_out, 1);
	close(cmd_data->pipe_fd[1]);
}
