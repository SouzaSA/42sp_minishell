/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_run.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 21:08:41 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/17 10:47:48 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"
#include "ft_signals.h"

static int	ft_forker(t_shell *shell, t_cmd_data *data, t_cmd_blk *blk);
static int	ft_child(t_shell *shell, t_cmd_data *data, t_cmd_blk *blk);
static int	ft_exec_cmd(t_shell *shell, t_cmd_data *data, t_cmd_blk *blk);
static void	ft_parent(t_cmd_data *data, t_cmd_blk *blk);

int	ft_cmd_run(t_shell *shell, t_cmd_data *data, t_ast *ast)
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
	data->blk = blk;
	rtn = ft_assignments(shell, blk->assign);
	rtn = ft_redirections(shell, data);
	rtn = ft_forker(shell, data, blk);
	if (data->cmd)
		free(data->cmd);
	ft_destroy_command(&blk);
	return (rtn);
}

static int	ft_forker(t_shell *shell, t_cmd_data *data, t_cmd_blk *blk)
{
	int		rtn;

	rtn = 0;
	if (pipe(data->pipe_fd) == -1)
		rtn = ft_put_msg_error(NULL, FLAG_ERROR_P);
	data->pid = fork();
	if (data->pid == -1)
		rtn = ft_put_msg_error(NULL, FLAG_ERROR_P);
	if (rtn == 0)
		data->forked = 1;
	ft_handle_parent_process_signals();
	if (rtn == 0 && data->pid == 0)
		rtn = ft_child(shell, data, blk);
	ft_parent(data, blk);
	return (rtn);
}

static int	ft_child(t_shell *shell, t_cmd_data *data, t_cmd_blk *blk)
{
	int	rtn;

	rtn = 0;
	ft_handle_child_process_signals();
	ft_destroy_tt(&shell->transition_table);
	rl_clear_history();
	ft_destroy_ast_stk(data->cmd_stk);
	if (data->fd_in >= 0 && data->fd_out > 0)
		rtn = ft_exec_cmd(shell, data, blk);
	else
	{
		close(data->pipe_fd[0]);
		close(data->pipe_fd[1]);
		ft_destroy_command(&blk);
		ft_destroy_shell(shell);
		if (data->fd_in < 0 || data->fd_out < 0)
			exit(g_exit_status);
		else
			exit(0);
	}
	return (rtn);
}

static int	ft_exec_cmd(t_shell *shell, t_cmd_data *data, t_cmd_blk *blk)
{
	char	**envp;

	close(data->pipe_fd[0]);
	data->cmd = ft_cmd_lst_to_array(shell, &blk->cmd);
	if (data->cmd)
	{
		ft_pipe_worker(data);
		envp = ft_construct_envp(shell->env_list);
		if (execve(data->cmd[0], data->cmd, envp) == -1)
			ft_put_msg_error("execve error", FLAG_ERROR_OWN);
		ft_split_destroy(envp);
	}
	if (data->fd_in > 0)
		close(data->fd_in);
	close(data->pipe_fd[1]);
	free(data->cmd);
	ft_destroy_command(&blk);
	ft_destroy_shell(shell);
	exit(g_exit_status);
}

static void	ft_parent(t_cmd_data *data, t_cmd_blk *blk)
{
	t_ast	*ast;

	ast = ft_lsttop(*data->cmd_stk);
	if (ft_lstsize(*data->cmd_stk) && ast->type != AST_AND \
		&& ast->type != AST_OR && blk && blk->cmd \
		&& !ft_strstr((char *)blk->cmd->content, "cat"))
	{
		waitpid(data->pid, NULL, 0);
	}
	else
		waitpid(data->pid, NULL, 1);
	close(data->pipe_fd[1]);
	if (data->fd_in > 0)
		close(data->fd_in);
}
