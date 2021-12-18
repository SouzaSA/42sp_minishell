/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:57:26 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/18 14:20:16 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void	ft_import_envp(t_shell *shell, char **envp);

void	ft_init_minishell(t_shell *shell, char **envp)
{
	ft_import_envp(shell, envp);
}

static void	ft_import_envp(t_shell *shell, char **envp)
{
	int				i;
	long			idx;
	t_dictionary	*dic_item;

	i = 0;
	shell->env_list = NULL;
	while (envp && envp[i])
	{
		dic_item = (t_dictionary *)malloc(sizeof(t_dictionary));
		idx = (long)(ft_strchr(envp[i], '=') - &envp[i][0]);
		dic_item->key = ft_substr(envp[i], 0, idx);
		dic_item->value = ft_substr(envp[i], idx + 1, ft_strlen(envp[i]));
		ft_export(shell, ft_lstnew(dic_item));
		i++;
	}
}
