/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_run_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:40:18 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/17 19:11:50 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor_bonus.h"

static int	ft_child(t_shell *shell, t_cmd_data *data, t_cmd_blk *cmd);
static int	ft_update_cmd_lst(t_list **cmd);
static int	ft_forker_builtin(t_shell *shell, t_cmd_data *data, t_cmd_blk *blk);
static int	ft_exec_builtin(t_shell *shell, t_cmd_data *data, t_cmd_blk *blk);

int	ft_builtin_run(t_shell *shell, t_cmd_data *data, t_ast *ast)
{
	int			rtn;

	rtn = 0;
	data->blk = ast->blk;
	free(ast);
	data->cmd = NULL;
	data->fd_in = 0;
	data->fd_out = 1;
	data->pid = -1;
	rtn = ft_assignments(shell, data->blk->assign);
	rtn = ft_redirections(shell, data);
	rtn = ft_forker_builtin(shell, data, data->blk);
	if (data->cmd)
		free(data->cmd);
	ft_destroy_command(&data->blk);
	return (rtn);
}

static int	ft_forker_builtin(t_shell *shell, t_cmd_data *data, t_cmd_blk *cmd)
{
	int		wstatus;
	int		rtn;
	t_ast	*ast;

	rtn = 0;
	ast = ft_lsttop(*data->cmd_stk);
	if (pipe(data->pipe_fd) == -1)
		rtn = ft_put_msg_error(NULL, FLAG_ERROR_P);
	data->pid = fork();
	if (data->pid == -1)
		rtn = ft_put_msg_error(NULL, FLAG_ERROR_P);
	if (rtn == 0)
		data->forked = 1;
	if (rtn == 0 && data->pid == 0)
		rtn = ft_child(shell, data, cmd);
	if (ft_lstsize(*data->cmd_stk) && ast->type != AST_AND \
		&& ast->type != AST_OR)
	{
		waitpid(data->pid, &wstatus, 0);
		if (!WIFSIGNALED(wstatus))
			g_exit_status = WEXITSTATUS(wstatus);
	}
	close(data->pipe_fd[1]);
	return (rtn);
}

static int	ft_child(t_shell *shell, t_cmd_data *data, t_cmd_blk *blk)
{
	int	rtn;

	rtn = 0;
	ft_destroy_tt(&shell->transition_table);
	rl_clear_history();
	ft_destroy_ast_stk(data->cmd_stk);
	rtn = ft_update_cmd_lst(&blk->cmd);
	if (!rtn && data->fd_in >= 0 && data->fd_out > 0)
		rtn = ft_exec_builtin(shell, data, blk);
	else
	{
		close(data->pipe_fd[0]);
		close(data->pipe_fd[1]);
		ft_destroy_command(&blk);
		ft_destroy_shell(shell);
		if (data->fd_in < 0 || data->fd_out < 0)
			exit(1);
		else
			exit(0);
	}
	ft_handle_parent_process_signals();
	close(data->pipe_fd[1]);
	return (rtn);
}

static int	ft_update_cmd_lst(t_list **cmd)
{
	int	rtn;

	rtn = 0;
	ft_expand_star(cmd);
	if (ft_lstsize(*cmd) > 1L << 12)
	{
		ft_expand_error((char *)(*cmd)->content, FLAG_ERROR_CMD);
		rtn = 1;
	}
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
