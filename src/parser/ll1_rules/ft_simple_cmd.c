/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:05:20 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/30 13:03:57 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_simple_cmd(t_list **symbol_stack, t_token *token)
{
	t_stk_node	*stk_node;
	t_stk_node	*stk_node_old;

	if (token->tok_type >= 0)
	{
		stk_node_old = (t_stk_node *)ft_lstpop(symbol_stack);
		if (token->tok_type == TS_WORD)
		{
			ft_stk_set_node(&stk_node, stk_node_old, NTS_SIMPLE_CMD2);
			ft_lstpush(symbol_stack, ft_stk_node(NTS_SIMPLE_CMD2));
			ft_stk_set_node(&stk_node, stk_node_old, TS_WORD);
			stk_node->ast_node->type = AST_CMD;
			stk_node->ast_node->cmd = (t_command *)malloc(sizeof(t_command));
			stk_node->ast_node->cmd->cmd = NULL;
			ft_lstadd_back(&stk_node->ast_node->cmd->cmd, ft_lstnew(ft_strdup(token->text)));
			ft_stk_set_node(&stk_node, stk_node_old, TS_WORD);
			ft_lstpush(symbol_stack, ft_stk_node(stk_node));
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

void	ft_simple_cmd1(t_list **symbol_stack, t_token *token)
{
	if (token->tok_type >= 0)
	{
		free(ft_lstpop(symbol_stack));
		ft_lstpush(symbol_stack, ft_stk_node(NTS_SIMPLE_CMD2));
		ft_lstpush(symbol_stack, ft_stk_node(TS_WORD));
	}
}

void	ft_simple_cmd2(t_list **symbol_stack, t_token *token)
{
	if (token->tok_type >= 0)
	{
		free(ft_lstpop(symbol_stack));
		ft_lstpush(symbol_stack, ft_stk_node(NTS_SULFIX));
	}
}
