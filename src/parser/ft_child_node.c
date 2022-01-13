/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:32:52 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/13 09:45:50 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_add_child_node(t_ast_node *parent, t_ast_node *child)
{
	t_ast_node	*sibling;

	if (!parent || !child)
		return ;
	if (!parent->first_child)
	{
		parent->first_child = child;
	}
	else
	{
		sibling = parent->first_child;
		while (sibling->next_sibling)
			sibling = sibling->next_sibling;
		sibling->next_sibling = child;
		child->prev_sibling = sibling;
	}
	parent->children++;
}
