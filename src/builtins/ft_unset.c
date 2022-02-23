/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:52:06 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/23 17:47:59 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void	ft_unset_worker(t_shell *shell, char *key);

int	ft_unset(t_shell *shell, t_list *cmds)
{
	while (cmds)
	{
		if (ft_isidentifier((char *)cmds->content))
			ft_unset_worker(shell, (char *)cmds->content);
		else
		{
			shell->error_status = 1;
			ft_unset_error((char *)cmds->content, FLAG_ERROR_OWN);
		}
		cmds = cmds->next;
	}
	return (0);
}

static void	ft_unset_worker(t_shell *shell, char *key)
{
	char	*dic_key;
	t_list	*node;
	t_list	*prev_node;

	if (shell && key && shell->env_list)
	{
		node = shell->env_list;
		prev_node = NULL;
		dic_key = ((t_dictionary *)shell->env_list)->key;
		while (node && ft_strcmp(dic_key, key) != 0)
		{
			prev_node = node;
			node = node->next;
			if (node)
				dic_key = ((t_dictionary *)node)->key;
		}
		if (node)
		{
			if (node == shell->env_list)
				ft_lstadd_front(&shell->env_list, node->next);
			else
				ft_lstadd_back(&prev_node, node->next);
			ft_lstdelone(node, &ft_destroy_dictionary_element);
		}
	}
}
