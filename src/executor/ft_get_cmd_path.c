/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 08:55:56 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/11 22:01:38 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

static char	*ft_join_cmd_path(char *command, char **path_list);
static int	ft_is_clean_str(char *cmd);
static char	*ft_search_cmd(char *command, char **path_list);

char	*ft_get_cmd_path(char *command, char **path_list)
{
	char	*aux;
	char	*path_cmd;

	path_cmd = NULL;
	aux = ft_str_remove_quotes(command);
	if (ft_checker_slash(aux) && access(aux, F_OK & X_OK) == 0)
		path_cmd = ft_strdup(aux);
	else if (ft_checker_slash(aux))
		ft_command_error(aux);
	else
		path_cmd = ft_join_cmd_path(aux, path_list);
	free(aux);
	return (path_cmd);
}

static char	*ft_join_cmd_path(char *command, char **path_list)
{
	char	*path_cmd;

	path_cmd = NULL;
	if (!ft_is_clean_str(command))
		path_cmd = ft_search_cmd(command, path_list);
	if (!path_cmd)
		ft_command_error(command);
	return (path_cmd);
}

static int	ft_is_clean_str(char *cmd)
{
	int	i;
	int	rtn;

	i = 0;
	rtn = 0;
	while (cmd && cmd[i] != '\0' && cmd[i] == 32)
		i++;
	if (i == (int)ft_strlen(cmd))
		rtn = 1;
	return (rtn);
}

static char	*ft_search_cmd(char *command, char **path_list)
{
	int		i;
	char	*path_cmd;
	char	*cmd_slashed;

	i = 0;
	path_cmd = NULL;
	cmd_slashed = ft_strjoin("/", command);
	while (path_list && path_list[i])
	{
		path_cmd = ft_strjoin(path_list[i], cmd_slashed);
		if (access(path_cmd, F_OK | X_OK) == 0)
			break ;
		free (path_cmd);
		path_cmd = NULL;
		i++;
	}
	free(cmd_slashed);
	return (path_cmd);
}
