/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipeline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:01:54 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/27 12:02:13 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_pipeline(t_syntax *stx_vars, enum e_symbol tok_type)
{
	t_stk_node	*stk_node;
	t_stk_node	*stk_node_old;

	if (tok_type >= 0)
	{
		stk_node_old = (t_stk_node *)ft_lstpop(&stx_vars->symbol_stack);
		stk_node_old->ast_node->children++;
		stk_node_old->ast_node->type = AST_TMP;
		stk_node_old->ast_node->first_child = ft_new_node(NTS_COMMAND);
		stk_node = (t_stk_node *)ft_stk_node(NTS_PIPELINE1);
		stk_node->ast_node = stk_node_old->ast_node;
		ft_lstpush(&stx_vars->symbol_stack, stk_node);
		stk_node = (t_stk_node *)ft_stk_node(NTS_COMMAND);
		stk_node->ast_node = stk_node_old->ast_node->first_child;
		ft_lstpush(&stx_vars->symbol_stack, stk_node);
		free(stk_node_old);
	}
}

void	ft_pipeline1(t_syntax *stx_vars, enum e_symbol tok_type)
{
	t_stk_node	*stk_node;
	t_stk_node	*stk_node_old;

	if (tok_type >= 0)
	{
		stk_node_old = (t_stk_node *)ft_lstpop(&stx_vars->symbol_stack);
		stk_node_old->ast_node->type = AST_PIPE;
		stk_node_old->ast_node->children++;
		stk_node_old->ast_node->first_child->next_sibling = ft_new_node(AST_TMP);
		stk_node = (t_stk_node *)ft_stk_node(NTS_PIPELINE);
		stk_node->ast_node = stk_node_old->ast_node->first_child->next_sibling;
		ft_lstpush(&stx_vars->symbol_stack, stk_node);
		ft_lstpush(&stx_vars->symbol_stack, ft_stk_node(tok_type));
		free(stk_node_old);
	}
}
