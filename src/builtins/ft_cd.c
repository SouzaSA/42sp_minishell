/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:43:00 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/04 08:10:31 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtins.h"

static int	ft_cd_home(t_shell *shell);
static int	ft_cd_swap(t_shell *shell);
static int	ft_cd_path(t_shell *shell, char *path);

int	ft_cd(t_shell *shell, t_list *cmds)
{
	int		len;

	len = ft_lstsize(cmds);
	shell->error_status = 0;
	if (cmds && !ft_strcmp("cd", (char *)cmds->content))
	{
		if (len == 1)
			return (ft_cd_home(shell));
		else if (len > 2)
			return (ft_cd_error(shell, "too many arguments", FLAG_ERROR_OWN));
		else if (!ft_strcmp("-", (char *)cmds->next->content))
			return (ft_cd_swap(shell));
		else
			return (ft_cd_path(shell, (char *)cmds->next->content));
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
	ft_pwd();
	shell->error_status = 0;
	return (0);
}

static int	ft_cd_path(t_shell *shell, char *path)
{
	struct stat	stats;

	stats.st_mode = 0;
	stat(path, &stats);
	if (!S_ISDIR(stats.st_mode))
	{
		shell->error_status = 1;
		return (ft_cd_error(shell, path, FLAG_ERROR_P));
	}
	if (chdir(path) != 0)
	{
		shell->error_status = 2;
		return (ft_cd_error(shell, path, FLAG_ERROR_P));
	}
	ft_update_env_pwds(shell, ft_strdup(path));
	shell->error_status = 0;
	return (0);
}
