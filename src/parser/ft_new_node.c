/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:33:08 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/13 12:20:31 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

t_ast_node	*ft_new_node(enum e_node_type type)
{
	t_ast_node	*node;

	node = (t_ast_node *)malloc(sizeof(t_ast_node));
	if (!node)
		return (NULL);
	ft_memset(node, 0, sizeof(t_ast_node));
	node->type = type;
	node->str = NULL;
	node->first_child = NULL;
	node->next_sibling = NULL;
	node->prev_sibling = NULL;
	return (node);
}
