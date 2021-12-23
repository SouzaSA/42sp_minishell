/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:48:25 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/23 11:12:33 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void	ft_child(char **cmd, char **path, char **envp);
static void	ft_cleaner_exit(char **path, char *cmd_path, char **cmd_params);

int	ft_execute(char **cmd, char **path, char **envp)
{
	int		pid;
	int		rtn;

	rtn = 0;
	pid = fork();
	if (pid == -1)
		rtn = ft_error_msg(NULL);
	if (rtn == 0)
	{
		if (pid == 0)
			ft_child(cmd, path, envp);
	}
	return (rtn);
}

static void	ft_child(char **cmd, char **path, char **envp)
{
	int		fd_in;
	char	*cmd_path;
	char	**cmd_params;

	cmd_path = ft_get_cmd_path(cmd_params[0], path);
	if (cmd_path)
		execve(cmd_path, cmd_params, envp);
	else
	ft_cleaner_exit(path, cmd_path, cmd_params);
}

static void	ft_cleaner_exit(char **path, char *cmd_path, char **cmd_params)
{
	int	i;

	i = 0;
	ft_cleaner_strstr(path);
	if (cmd_path)
		free(cmd_path);
	if (cmd_params)
	{
		while (cmd_params[i])
		{
			free(cmd_params[i]);
			i++;
		}
		free(cmd_params);
	}
	exit(1);
}
