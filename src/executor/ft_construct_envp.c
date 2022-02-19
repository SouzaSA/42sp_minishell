/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_construct_envp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:51:02 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/17 14:30:32 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

char	**ft_construct_envp(t_list *env_lst)
{
	int		i;
	char	*key;
	char	**envp;
	t_list	*node;

	i = 0;
	envp = (char **)malloc((ft_lstsize(env_lst) + 1)* sizeof(char *));
	node = env_lst;
	while (node)
	{
		key = ft_strjoin(((t_dictionary *)node->content)->key, "=");
		envp[i] = ft_strjoin(key, ((t_dictionary *)node->content)->value);
		free(key);
		i++;
		node = node->next;
	}
	envp[i] = NULL;
	return (envp);
}
