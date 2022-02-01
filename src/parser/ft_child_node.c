/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:32:52 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/01 11:43:54 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

t_ast	*ft_add_child_node(t_ast *parent, t_ast *child)
{
	t_ast	*sibling;

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
	return (child);
}
