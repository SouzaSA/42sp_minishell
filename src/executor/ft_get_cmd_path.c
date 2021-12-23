/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:27:48 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/30 15:46:30 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void	ft_command_error(char *command);
static char	*ft_join_cmd_path(char *command, char **path_list);

char	*ft_get_cmd_path(char *command, char **path_list)
{
	char	*path_cmd;

	path_cmd = NULL;
	if (ft_checker_slash(command) && access(command, X_OK) == 0)
		path_cmd = ft_strdup(command);
	else if (!ft_checker_slash(command))
		path_cmd = ft_join_cmd_path(command, path_list);
	else
		ft_command_error(command);
	return (path_cmd);
}

static char	*ft_join_cmd_path(char *command, char **path_list)
{
	int		i;
	char	*path_cmd;
	char	*cmd_slashed;

	i = 0;
	path_cmd = NULL;
	cmd_slashed = ft_strjoin("/", command);
	while (path_list[i])
	{
		path_cmd = ft_strjoin(path_list[i], cmd_slashed);
		if (access(path_cmd, X_OK) == 0)
			break ;
		free (path_cmd);
		path_cmd = NULL;
		i++;
	}
	free(cmd_slashed);
	if (!path_cmd)
		ft_command_error(command);
	return (path_cmd);
}

static void	ft_command_error(char *command)
{
	int	error_msg;

	error_msg = ft_strjoin("command not found: ", command);
	ft_throws_error_msg(error_msg);
	free(error_msg);
}
