/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipeline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:01:54 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/03 17:58:25 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_pipeline(t_list **symbol_stack, enum e_symbol tok_type)
{
	t_stk_node	*stk_node;
	t_stk_node	*stk_node_old;

	if (tok_type >= 0)
	{
		stk_node_old = (t_stk_node *)ft_lstpop(symbol_stack);
		ft_stk_set_node(&stk_node, stk_node_old, NTS_PIPELINE1);
		ft_lstpush(symbol_stack, stk_node);
		ft_stk_add_child(&stk_node, stk_node_old, NTS_COMMAND);
		ft_lstpush(symbol_stack, stk_node);
		free(stk_node_old);
	}
}

void	ft_pipeline1(t_list **symbol_stack, enum e_symbol tok_type)
{
	t_stk_node	*stk_node;
	t_stk_node	*stk_node_old;

	if (tok_type >= 0)
	{
		stk_node_old = (t_stk_node *)ft_lstpop(symbol_stack);
		ft_stk_add_child(&stk_node, stk_node_old, NTS_PIPELINE);
		ft_lstpush(symbol_stack, stk_node);
		ft_stk_set_node(&stk_node, stk_node_old, tok_type);
		stk_node->ast_node->type = AST_PIPE;
		ft_lstpush(symbol_stack, stk_node);
		free(stk_node_old);
	}
}
