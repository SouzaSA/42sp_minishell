/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env_value_by_key.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:39:09 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/05 18:48:02 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

char	*ft_get_env_value_by_key(t_shell *shell, char *key)
{
	t_list	*node;
	char	*value;

	node = shell->env_list;
	value = NULL;
	while (node)
	{
		if (!ft_strcmp(key, ((t_dictionary *)node->content)->key))
			value = ((t_dictionary *)node->content)->value;
		node = node->next;
	}
	return (value);
}
