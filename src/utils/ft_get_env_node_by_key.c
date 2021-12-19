/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env_node_by_key.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:55:04 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/19 17:49:43 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_list	*ft_get_env_node_by_key(t_shell *shell, char *key)
{
	t_list	*node;
	t_list	*return_node;

	node = shell->env_list;
	return_node = NULL;
	while (node)
	{
		if (!ft_strcmp(key, ((t_dictionary *)node->content)->key))
			return_node = node;
		node = node->next;
	}
	return (return_node);
}
