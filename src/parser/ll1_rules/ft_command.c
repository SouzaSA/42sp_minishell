/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:03:04 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/27 12:46:55 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_command(t_syntax *stx_vars, enum e_symbol tok_type)
{
	t_stk_node	*stk_node;
	t_stk_node	*stk_node_old;

	if (tok_type >= 0)
	{
		stk_node_old = (t_stk_node *)ft_lstpop(&stx_vars->symbol_stack);
		stk_node_old->ast_node->children++;
		stk_node_old->ast_node->type = AST_TMP;
		if (tok_type == TS_LBRACE)
		{
			ft_lstpush(&stx_vars->symbol_stack, ft_stk_node(NTS_COMMAND1));
			ft_lstpush(&stx_vars->symbol_stack, ft_stk_node(NTS_SUBSHELL));
		}
		else
		{
			stk_node_old->ast_node->first_child = ft_new_node(AST_CMD);
			stk_node = (t_stk_node *)ft_stk_node(NTS_SIMPLE_CMD);
			stk_node->ast_node = stk_node_old->ast_node;
			ft_lstpush(&stx_vars->symbol_stack, stk_node);
		}
		free(stk_node_old);
	}
}

void	ft_command1(t_syntax *stx_vars, enum e_symbol tok_type)
{
	if (tok_type >= 0)
	{
		free(ft_lstpop(&stx_vars->symbol_stack));
		ft_lstpush(&stx_vars->symbol_stack, ft_stk_node(NTS_REDIR_LST));
	}
}
