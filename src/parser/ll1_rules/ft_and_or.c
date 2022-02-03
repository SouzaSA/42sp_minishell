/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and_or.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 10:58:53 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/03 17:54:59 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_and_or(t_list **symbol_stack, enum e_symbol tok_type)
{
	t_stk_node	*stk_node;
	t_stk_node	*stk_node_old;

	if (tok_type >= 0)
	{
		stk_node_old = (t_stk_node *)ft_lstpop(symbol_stack);
		stk_node_old->ast_node->type = AST_TMP;
		ft_stk_set_node(&stk_node, stk_node_old, NTS_AND_OR1);
		ft_lstpush(symbol_stack, stk_node);
		ft_stk_add_child(&stk_node, stk_node_old, NTS_PIPELINE);
		ft_lstpush(symbol_stack, stk_node);
		free(stk_node_old);
	}
}

void	ft_and_or1(t_list **symbol_stack, enum e_symbol tok_type)
{
	t_stk_node	*stk_node;
	t_stk_node	*stk_node_old;

	if (tok_type >= 0)
	{
		stk_node_old = (t_stk_node *)ft_lstpop(symbol_stack);
		if (tok_type == TS_AND_IF)
			stk_node_old->ast_node->type = AST_AND;
		else
			stk_node_old->ast_node->type = AST_OR;
		ft_stk_add_child(&stk_node, stk_node_old, NTS_AND_OR);
		ft_lstpush(symbol_stack, stk_node);
		ft_stk_set_node(&stk_node, stk_node_old, tok_type);
		stk_node->ast_type = stk_node_old->ast_node->type;
		ft_lstpush(symbol_stack, stk_node);
		free(stk_node_old);
	}
}
