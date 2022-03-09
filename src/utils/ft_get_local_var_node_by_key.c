/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_local_var_node_by_key.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:49:00 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/08 21:37:21 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_list	*ft_get_local_var_node_by_key(t_shell *shell, char *key)
{
	t_list	*node;
	t_list	*return_node;

	node = shell->vars;
	return_node = NULL;
	while (node)
	{
		if (!ft_strcmp(key, ((t_dictionary *)node->content)->key))
			return_node = node;
		node = node->next;
	}
	return (return_node);
}
