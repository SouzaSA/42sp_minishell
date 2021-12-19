/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:43:00 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/19 19:23:05 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_cd(t_shell *shell, char **cmd)
{
	shell->error_status = 0;
	if (cmd && !ft_strcmp("cd", cmd[0]))
	{
		if (!cmd[1])
			return (ft_cd_home(shell));
		else if (cmd[1] && cmd[2])
		{
			shell->error_status = 1;
			return (ft_put_msg_error(shell, "cd: too many arguments"));
		}
		else if (!ft_strcmp("-", cmd[1]))
		{
			return (ft_cd_swap(shell));
		}
		else
		{
			return (ft_cd_path(shell, cmd[1]));
		}
	}
	return (1);
}

static int	ft_cd_home(t_shell *shell)
{
	char	*home_path;
	t_list	*node;

	if (shell && shell->env_list)
	{
		node = ft_get_env_node_by_key(shell, "HOME");
		if (!node)
		{
			shell->error_status = 1;
			return (ft_put_msg_error(shell, "cd: HOME not set"));
		}
		home_path = ft_strdup(((t_dictionary)node->content)->value);
		if (chdir(home_path) != 0)
			return (ft_put_msg_error(shell, strerror(erno)));
		ft_update_env_pwds(shell, home_path);
		shell->error->status = 0;
	}
	return (0);
}

static int	ft_cd_swap(t_shell *shell)
{
	char	*old_pwd;

	old_pwd = ft_get_env_value_by_key(shell, "OLDPWD");
	if (!old_pwd)
	{
		shell->error_status = 1;
		return (ft_put_msg_error(shell, "cd: OLDPWD not set"));
	}
	if (chdir(home_path) != 0)
		return (ft_put_msg_error(shell, strerror(erno)));
	ft_update_env_pwds(shell, ft_strdup(old_pwd));
	return (0);
}

static int	ft_cd_path(t_shell *shell, char *path)
{
	char 	*msg;

	if (chdir(path) != 0)
	{
		msg = ft_strjoin("cd: ", path);
		ft_put_msg_error(shell, strerror(erno));
		free (msg);
		return (1);
	}
	ft_update_env_pwds(shell, ft_strdup(path));
	return (0);
}
