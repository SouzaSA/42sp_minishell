/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:43:00 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/19 16:58:33 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_cd(t_shell *shell, char **cmd)
{
	if (cmd && !ft_strcmp("cd", cmd[0]))
	{
		if (!cmd[1])
			return (ft_cd_home(shell));
		else if (cmd[1] && cmd[2])
			return (ft_throws_error_msg("minishell: cd: too many arguments"));
		else if (!ft_strcmp("~", cmd[1]))
			return (ft_cd_tilde(shell));
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
		home_path = ((t_dictionary)shell->env_list->content)->key;
		node = shell->env_list;
		while (node && !ft_strcmp("HOME", home_path))
		{
			node = node->next;
			if (node)
				home_path = ((t_dictionary)node->content)->key;
		}
		if (!node)
			return (ft_throws_error_msg("minishell: cd: HOME not set"));
		ft_update_env_PWD(shell, ((t_dictionary)node->content)->value);
	}
	return (0);
}