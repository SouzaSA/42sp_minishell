/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:05:20 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/03 18:01:02 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_simple_cmd(t_list **symbol_stack, enum e_symbol tok_type)
{
	t_stk_node	*stk_node;
	t_stk_node	*stk_node_old;

	if (tok_type >= 0)
	{
		stk_node_old = (t_stk_node *)ft_lstpop(symbol_stack);
		if (tok_type == TS_WORD)
		{
			ft_stk_set_node(&stk_node, stk_node_old, NTS_SIMPLE_CMD2);
			ft_lstpush(symbol_stack, stk_node);
			ft_stk_set_node(&stk_node, stk_node_old, TS_WORD);
			stk_node->ast_type = AST_CMD;
			ft_lstpush(symbol_stack, stk_node);
		}
		else
		{
			ft_stk_set_node(&stk_node, stk_node_old, NTS_SIMPLE_CMD1);
			ft_lstpush(symbol_stack, stk_node);
			ft_stk_set_node(&stk_node, stk_node_old, NTS_PREFIX);
			ft_lstpush(symbol_stack, stk_node);
		}
		free(stk_node_old);
	}
}

void	ft_simple_cmd1(t_list **symbol_stack, enum e_symbol tok_type)
{
	t_stk_node	*stk_node;
	t_stk_node	*stk_node_old;

	if (tok_type >= 0)
	{
		stk_node_old = (t_stk_node *)ft_lstpop(symbol_stack);
		ft_stk_set_node(&stk_node, stk_node_old, NTS_SIMPLE_CMD2);
		ft_lstpush(symbol_stack, stk_node);
		ft_stk_set_node(&stk_node, stk_node_old, TS_WORD);
		stk_node->ast_type = AST_CMD;
		ft_lstpush(symbol_stack, stk_node);
		free(stk_node_old);
	}
}

void	ft_simple_cmd2(t_list **symbol_stack, enum e_symbol tok_type)
{
	t_stk_node	*stk_node;
	t_stk_node	*stk_node_old;

	if (tok_type >= 0)
	{
		stk_node_old = (t_stk_node *)ft_lstpop(symbol_stack);
		ft_stk_set_node(&stk_node, stk_node_old, NTS_SULFIX);
		ft_lstpush(symbol_stack, stk_node);
		free(stk_node_old);
	}
}
