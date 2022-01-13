/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_node_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:33:03 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/13 11:25:18 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_free_node_tree(t_ast_node *node)
{
	t_ast_node	*child;
	t_ast_node	*next;

	if (!node)
		return ;
	child = node->first_child;
	while (child)
	{
		next = child->next_sibling;
		ft_free_node_tree(child);
		child = next;
	}
	if (node->str)
		free(node->str);
	free(node);
}
