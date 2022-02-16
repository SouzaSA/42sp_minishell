/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:57:26 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/16 08:25:41 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void	ft_import_envp(t_shell *shell, char **envp);

void	ft_init_minishell(t_shell *shell, char **envp)
{
	int	i;

	i = 0;
	shell->vars = NULL;
	ft_import_envp(shell, envp);
	shell->transition_table = malloc(NUM_NTS * sizeof(void ***));
	while (i < NUM_NTS)
	{
		shell->transition_table[i] = malloc(NUM_TS * sizeof(void **));
		i++;
	}
	ft_fill_transition_table(shell->transition_table);
}

static void	ft_import_envp(t_shell *shell, char **envp)
{
	int		i;
	long	idx;
	char	*key;
	char	*value;

	i = 0;
	shell->env_list = NULL;
	shell->error_status = 0;
	while (envp && envp[i])
	{
		idx = (long)(ft_strchr(envp[i], '=') - &envp[i][0]);
		key = ft_substr(envp[i], 0, idx);
		value = ft_substr(envp[i], idx + 1, ft_strlen(envp[i]));
		ft_export(shell, key, value);
		i++;
	}
}
