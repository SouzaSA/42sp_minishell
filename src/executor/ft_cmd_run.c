/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_run.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 21:08:41 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/05 09:33:59 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"
#include "ft_minishell.h"

static char	**ft_cmd_lst_to_array(t_list *cmd);
static int	ft_forker(t_shell *shell, t_cmd_data *data, t_cmd_blk *cmd);
static int	ft_exec_cmd(t_shell *shell, t_cmd_data *data, t_cmd_blk *cmd);
static void	ft_pipe_worker(t_cmd_data *data);

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
	rtn = ft_assignments(shell, blk->assign);
	rtn = ft_redirections(blk->redir, &data->fd_in, &data->fd_out);
	rtn = ft_forker(shell, data, blk);
	if (data->cmd)
		free(data->cmd);
	ft_destroy_command(&blk);
	return (rtn);
}

static char	**ft_cmd_lst_to_array(t_list *cmd)
{
	int		i;
	t_list	*node;
	char	**cmd_array;

	i = 0;
	cmd_array = NULL;
	if (cmd)
	{
		cmd_array = (char **)malloc((ft_lstsize(cmd) + 1) * sizeof(char *));
		if (cmd_array)
		{
			node = cmd;
			while (node)
			{
				cmd_array[i] = (char *)node->content;
				node = node->next;
				i++;
			}
			cmd_array[i] = NULL;
		}
	}
	return (cmd_array);
}

static int	ft_forker(t_shell *shell, t_cmd_data *data, t_cmd_blk *cmd)
{
	int	rtn;

	rtn = 0;
	if (pipe(data->pipe_fd) == -1)
		rtn = ft_put_msg_error(NULL, FLAG_ERROR_P);
	data->pid = fork();
	ft_handle_process_signals();
	if (data->pid == -1)
		rtn = ft_put_msg_error(NULL, FLAG_ERROR_P);
	if (rtn == 0 && data->pid == 0)
	{
		if (data->fd_in >= 0 && data->fd_out > 0)
			rtn = ft_exec_cmd(shell, data, cmd);
		else
		{
			close(data->pipe_fd[0]);
			close(data->pipe_fd[1]);
			ft_destroy_ast_stk(data->cmd_stk);
			ft_destroy_command(&cmd);
			rl_clear_history();
			ft_destroy_shell(shell);
			if (data->fd_in < 0 &&data->fd_out < 0)
				exit(1);
			else
				exit(0);
		}
	}
	waitpid(-1, NULL, WNOHANG);
	close(data->pipe_fd[1]);
	return (rtn);
}

static int	ft_exec_cmd(t_shell *shell, t_cmd_data *data, t_cmd_blk *blk)
{
	char	**cmd_args;
	char	**envp;

	cmd_args = NULL;
	close(data->pipe_fd[0]);
	data->cmd = ft_cmd_lst_to_array(blk->cmd);
	if (data->cmd)
		cmd_args = ft_construct_path(data->cmd, shell->env_list);
	if (cmd_args && cmd_args[0])
	{
		ft_pipe_worker(data);
		envp = ft_construct_envp(shell->env_list);
		if (execve(cmd_args[0], cmd_args, envp) == -1)
			ft_put_msg_error("execve error", FLAG_ERROR_OWN);
		free(cmd_args[0]);
		ft_split_destroy(envp);
	}
	free(cmd_args);
	if (ft_lstsize(*data->cmd_stk))
		ft_destroy_ast_stk(data->cmd_stk);
	ft_destroy_command(&blk);
	rl_clear_history();
	ft_destroy_shell(shell);
	exit(127);
}

static void	ft_pipe_worker(t_cmd_data *data)
{
	if (data->fd_in > 0)
	{
		dup2(data->fd_in, 0);
		close(data->fd_in);
		data->fd_in = 0;
	}
	if (data->fd_out == 1 && data->pipe_flag)
		dup2(data->pipe_fd[1], 1);
	else if (data->fd_out > 1)
		dup2(data->fd_out, 1);
	close(data->pipe_fd[1]);
}
