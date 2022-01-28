/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_set_add_child.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:59:48 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/27 21:01:58 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	*ft_stk_set_add_child(t_stk_node **new, t_stk_node *old, int type)
{
	old->ast_node->children++;
	*new = (t_stk_node *)ft_stk_node(NTS_AND_OR);
	old->ast_node->first_child->next_sibling = ft_new_node(AST_TMP);
	(*new)->ast_node = old->ast_node->first_child->next_sibling;
}
