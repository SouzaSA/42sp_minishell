/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subshell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:04:12 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/19 09:53:12 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_subshell(t_list **symbol_stack, enum e_symbol tok_type)
{
	t_stk_node	*stk_node;
	t_stk_node	*stk_node_old;

	if (tok_type >= 0)
	{
		stk_node_old = ft_lstpop(symbol_stack);
		stk_node_old->ast_node->type = AST_SUBSHELL;
		ft_stk_set_node(&stk_node, stk_node_old, TS_RBRACE);
		ft_lstpush(symbol_stack, stk_node);
		ft_stk_add_child(&stk_node, stk_node_old, NTS_AND_OR);
		ft_lstpush(symbol_stack, stk_node);
		ft_stk_set_node(&stk_node, stk_node_old, TS_LBRACE);
		ft_lstpush(symbol_stack, stk_node);
		free(stk_node_old);
	}
}
