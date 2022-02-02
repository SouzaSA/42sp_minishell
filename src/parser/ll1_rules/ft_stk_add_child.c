/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_add_child.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:59:48 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/02 10:12:35 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	*ft_stk_add_child(t_stk_node **new, t_stk_node *old, t_token *token, \
	enum e_symbol stk_type)
{
	t_ast	*sibling;

	*new = (t_stk_node *)ft_stk_node(stk_type);
	(*new)->token = token;
	sibling = ft_add_child_node(old->ast_node, ft_new_node(AST_TMP));
	(*new)->ast_node = sibling;
}
