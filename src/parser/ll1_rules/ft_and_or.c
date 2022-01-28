/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and_or.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 10:58:53 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/27 21:06:01 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_and_or(t_syntax *stx_vars, enum e_symbol tok_type)
{
	t_stk_node	*stk_node;
	t_stk_node	*stk_node_old;

	if (tok_type >= 0)
	{
		stk_node_old = (t_stk_node *)ft_lstpop(&stx_vars->symbol_stack);
		stk_node_old->ast_node->children++;
		stk_node_old->ast_node->type = AST_TMP;
		ft_stk_set_node_send(&stk_node, stk_node_old, NTS_AND_OR1);
		ft_lstpush(&stx_vars->symbol_stack, stk_node);
		ft_stk_set_node(&stk_node, stk_node_old, NTS_PIPELINE);
		ft_lstpush(&stx_vars->symbol_stack, stk_node);
		free(stk_node_old);
	}
}

void	ft_and_or1(t_syntax *stx_vars, enum e_symbol tok_type)
{
	t_stk_node	*stk_node;
	t_stk_node	*stk_node_old;

	if (tok_type >= 0)
	{
		stk_node_old = (t_stk_node *)ft_lstpop(&stx_vars->symbol_stack);
		if (tok_type == TS_AND_IF)
			stk_node_old->ast_node->type = AST_AND;
		else
			stk_node_old->ast_node->type = AST_OR;
		ft_stk_set_add_child(&stk_node, stk_node_old, NTS_AND_OR);
		ft_lstpush(&stx_vars->symbol_stack, stk_node);
		ft_lstpush(&stx_vars->symbol_stack, ft_stk_node(tok_type));
		free(stk_node_old);
	}
}
