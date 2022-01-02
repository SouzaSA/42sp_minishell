/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_node_val_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:33:16 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/23 18:33:17 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_set_node_val_str(t_node *node, char *val)
{
	char	*val2;

	node->val_type = VAL_STR;
	if (!val)
	{
		node->val.str = NULL;
	}
	else
	{
		val2 = malloc(strlen(val) + 1);
		if (!val2)
		{
			node->val.str = NULL;
		}
		else
		{
			ft_strcpy(val2, val);
			node->val.str = val2;
		}
	}
}
