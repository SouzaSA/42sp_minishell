/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and_or.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 10:58:53 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/25 21:04:41 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_and_or(t_syntax *stx_vars, enum e_symbol tok_type)
{
	t_stk_node	*node;
	t_stk_node	*node_old;

	if (tok_type >= 0)
	{
		node_old = (t_stk_node *)ft_lstpop(&stx_vars->symbol_stack);
		node_old->ast_node->children++;
		node_old->ast_node->first_child = ft_new_node(AST_PIPE);
		node_old->ast_node->first_child->next_sibling = ft_new_node(AST_AND_OR);
		free(node_old);
		node = (t_stk_node *)ft_stk_node(NTS_AND_OR1);
		node->ast_node = node_old->ast_node->first_child->next_sibling;
		ft_lstpush(&stx_vars->symbol_stack, node);
		node = (t_stk_node *)ft_stk_node(NTS_PIPELINE);
		node->ast_node = node_old->ast_node->first_child;
		ft_lstpush(&stx_vars->symbol_stack, ft_stk_node(NTS_PIPELINE));
	}
}

void	ft_and_or1(t_syntax *stx_vars, enum e_symbol tok_type)
{
	t_stk_node	*node;
	t_stk_node	*node_old;

	if (tok_type >= 0)
	{
		node_old = (t_stk_node *)ft_lstpop(&stx_vars->symbol_stack);

		free(node_old);
		free(ft_lstpop(&stx_vars->symbol_stack));
		ft_lstpush(&stx_vars->symbol_stack, ft_stk_node(NTS_AND_OR));
		ft_lstpush(&stx_vars->symbol_stack, ft_stk_node(tok_type));
	}
}
