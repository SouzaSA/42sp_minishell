/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_run.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 21:08:41 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/19 20:51:06 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

static char	**ft_cmd_lst_to_array(t_list *cmd);
static int	ft_forker(t_shell *shell, t_cmd_data *cmd_data, t_command *cmd);
static int	ft_exec_cmd(t_shell *shell, t_cmd_data *cmd_data, t_command *cmd);

int	ft_cmd_run(t_shell *shell, t_cmd_data *cmd_data, t_command *cmd)
{
	int	rtn;

	rtn = 0;
	cmd_data->cmd = NULL;
	cmd_data->fd_in = 0;
	cmd_data->fd_out = 1;
	rtn = ft_assignments(shell, cmd->assign); // TODO CLEAN and print error msg
	rtn = ft_redirections(cmd->redir, &cmd_data->fd_in, &cmd_data->fd_out);
	cmd_data->cmd = ft_cmd_lst_to_array(cmd->cmd);
	if (!cmd_data->cmd)
		rtn = 1;
	if (rtn == 0)
		rtn = ft_forker(shell, cmd_data, cmd);
	if (cmd_data->cmd)
		free(cmd_data->cmd);
	return(rtn);
}

static char	**ft_cmd_lst_to_array(t_list *cmd)
{
	int		i;
	t_list	*node;
	char 	**cmd_array;

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

static int	ft_forker(t_shell *shell, t_cmd_data *cmd_data, t_command *cmd)
{
	int	rtn;

	rtn = 0;

	if (pipe(cmd_data->pipe_fd) == -1)
		rtn = ft_put_msg_error(NULL, FLAG_ERROR_P);
	cmd_data->pid = fork();
	if (cmd_data->pid == -1)
		rtn = ft_put_msg_error(NULL, FLAG_ERROR_P);
	if (rtn == 0 && cmd_data->pid == 0)
		rtn = ft_exec_cmd(shell, cmd_data, cmd);
	return(rtn);
}

static int	ft_exec_cmd(t_shell *shell, t_cmd_data *cmd_data, t_command *cmd)
{
	char	**cmd_args;
	char	**envp;

	close(cmd_data->pipe_fd[0]);
	cmd_args = ft_construct_path(cmd_data->cmd, shell->env_list);
	if (cmd_args[0])
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
		envp = ft_construct_envp(shell->env_list);
		if (execve(cmd_args[0], cmd_args, envp) == -1)
			ft_put_msg_error("execve error", FLAG_ERROR_OWN);
		free(cmd_args[0]);
		ft_split_destroy(envp);
	}
	free(cmd_args);
	ft_destroy_command(&cmd);
	rl_clear_history();
	ft_destroy_shell(shell);
	exit(127);//tirar vazamentos
	return (1);
}
