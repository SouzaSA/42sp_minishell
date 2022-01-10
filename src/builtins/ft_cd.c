/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:43:00 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/09 10:51:09 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static int	ft_cd_home(t_shell *shell);
static int	ft_cd_swap(t_shell *shell);
static int	ft_cd_path(t_shell *shell, char *path);
static int	ft_cd_error(t_shell *shell, char *msg, int error_flag);

int g_errnum = 0;

int	ft_cd(t_shell *shell, char **cmd)
{
	shell->error_status = 0;
	if (cmd && !ft_strcmp("cd", cmd[0]))
	{
		if (!cmd[1])
			return (ft_cd_home(shell));
		else if (cmd[1] && cmd[2])
			return (ft_cd_error(shell, "too many arguments", FLAG_ERROR_OWN));
		else if (!ft_strcmp("-", cmd[1]))
			return (ft_cd_swap(shell));
		else
			return (ft_cd_path(shell, cmd[1]));
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
			return (ft_cd_error(shell, "HOME not set", FLAG_ERROR_OWN));
		home_path = ft_strdup(((t_dictionary *)node->content)->value);
		if (chdir(home_path) != 0)
			return (ft_cd_error(shell, home_path, FLAG_ERROR_P));
		ft_update_env_pwds(shell, home_path);
		shell->error_status = 0;
	}
	return (0);
}

static int	ft_cd_swap(t_shell *shell)
{
	char	*old_pwd;

	old_pwd = ft_get_env_value_by_key(shell, "OLDPWD");
	if (!old_pwd)
		return (ft_cd_error(shell, "OLDPWD not set", FLAG_ERROR_OWN));
	if (chdir(old_pwd) != 0)
		return (ft_cd_error(shell, old_pwd, FLAG_ERROR_P));
	ft_update_env_pwds(shell, ft_strdup(old_pwd));
	ft_pwd(shell);
	shell->error_status = 0;
	return (0);
}

static int	ft_cd_path(t_shell *shell, char *path)
{
	struct stat	stats;

	stat(path, &stats);
	if (S_ISDIR(stats.st_mode))
	{
		g_errnum = ENOTDIR;
		return (ft_cd_error(shell, path, FLAG_ERROR_STR));
	}
	if (chdir(path) != 0)
	{
		g_errnum = ENOENT;
		return (ft_cd_error(shell, path, FLAG_ERROR_STR));
	}
	ft_update_env_pwds(shell, ft_strdup(path));
	shell->error_status = 0;
	return (0);
}

static int	ft_cd_error(t_shell *shell, char *msg, int error_flag)
{
	char	*cd_err_msg;

	cd_err_msg = ft_strjoin("cd: ", msg);
	ft_put_msg_error(cd_err_msg, error_flag);
	free(cd_err_msg);
	shell->error_status = 1;
	return (1);
}
