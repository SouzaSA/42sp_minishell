/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:57:26 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/16 21:16:46 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_init_minishell(t_shell *shell, char **envp)
{
	int				i;
	long	idx;
	t_dictionary	*dic_item;

	i = 0;
	shell->env_list = NULL;
	while (envp && envp[i])
	{
		dic_item = (t_dictionary *)malloc(sizeof(t_dictionary));
		idx = (long)(ft_strchr(envp[i], '=') - &envp[i][0]);
		dic_item->key = ft_substr(envp[i], 0, idx);
		dic_item->value = ft_substr(envp[i], idx + 1, ft_strlen(envp[i]));
		ft_lstadd_back(&shell->env_list, ft_lstnew(dic_item));
		i++;
	}
}