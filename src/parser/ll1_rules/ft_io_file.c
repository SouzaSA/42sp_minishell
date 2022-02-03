/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:19:26 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/03 12:30:11 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_io_file(t_list **symbol_stack, t_token *token)
{
	t_stk_node	*stk_node;
	t_stk_node	*stk_node_old;

	if (token->tok_type >= 0)
	{
		stk_node_old = (t_stk_node *)ft_lstpop(symbol_stack);
		ft_stk_set_node(&stk_node, stk_node_old, TS_WORD);
		stk_node->ast_type = AST_REDIR;
		ft_lstpush(symbol_stack, stk_node);
		ft_stk_set_node(&stk_node, stk_node_old, token->tok_type);
		stk_node->ast_type = AST_REDIR;
		ft_lstpush(symbol_stack, stk_node);
		free(stk_node_old);
	}
}
