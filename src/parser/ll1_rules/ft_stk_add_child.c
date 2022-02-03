/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_add_child.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:59:48 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/03 18:09:12 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	*ft_stk_add_child(t_stk_node **new, t_stk_node *old, int stk_type)
{
	t_ast	*sibling;

	*new = (t_stk_node *)ft_stk_node(stk_type);
	sibling = ft_add_child_node(old->ast_node, ft_new_node(AST_TMP));
	(*new)->ast_node = sibling;
	return (sibling);
}
