/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_local_var_by_key.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:47:17 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/05 19:14:53 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

char	*ft_get_local_var_by_key(t_shell *shell, char *key)
{
	t_list	*node;
	char	*value;

	node = shell->vars;
	value = NULL;
	while (node)
	{
		if (!ft_strcmp(key, ((t_dictionary *)node->content)->key))
			value = ((t_dictionary *)node->content)->value;
		node = node->next;
	}
	return (value);
}
