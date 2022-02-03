/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:03:04 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/02 18:49:39 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_command(t_list **symbol_stack, t_token *token)
{
	t_stk_node	*stk_node;
	t_stk_node	*stk_node_old;

	if (token->tok_type >= 0)
	{
		stk_node_old = (t_stk_node *)ft_lstpop(symbol_stack);
		stk_node_old->ast_node->type = AST_TMP;
		if (token->tok_type == TS_LBRACE)
		{
			ft_stk_set_node(&stk_node, stk_node_old, NTS_COMMAND1);
			ft_lstpush(symbol_stack, stk_node);
			ft_stk_add_child(&stk_node, stk_node_old, token, NTS_SUBSHELL);
			ft_lstpush(symbol_stack, stk_node);
		}
		else
		{
			ft_stk_set_node(&stk_node, stk_node_old, NTS_SIMPLE_CMD);
			ft_lstpush(symbol_stack, stk_node);
		}
		free(stk_node_old);
	}
}

void	ft_command1(t_list **symbol_stack, t_token *token)
{
	t_stk_node	*stk_node;
	t_stk_node	*stk_node_old;

	if (token->tok_type >= 0)
	{
		stk_node_old = (t_stk_node *)ft_lstpop(symbol_stack);
		ft_stk_set_node(&stk_node, stk_node_old, NTS_REDIR_LST);
		ft_lstpush(symbol_stack, stk_node);
		free(stk_node_old);
	}
}
