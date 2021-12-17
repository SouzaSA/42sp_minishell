/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_var_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:39:09 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/16 20:23:31 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*ft_get_var_value(t_shell *shell, char *var)
{
	t_list	*node;
	char	*value;

	node = shell->env_list;
	value = NULL;
	while (node)
	{
		if (!ft_strcmp(var, (char *)node->content))
			value = (char *)node->content;
		node = node->next;
	}
	return (value);
}

