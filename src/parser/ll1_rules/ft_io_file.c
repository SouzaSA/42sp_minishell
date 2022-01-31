/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:19:26 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/31 12:12:07 by sde-alva         ###   ########.fr       */
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
		ft_lstadd_back(&stk_node->ast_node->cmd->redir, ft_lstnew(ft_strdup(token->text)));
		ft_lstpush(symbol_stack, ft_stk_node(TS_WORD));
		ft_lstadd_back(&stk_node->ast_node->cmd->redir, ft_lstnew(ft_strdup(token->text)));
		ft_lstpush(symbol_stack, ft_stk_node(token->tok_type));
		free(stk_node_old);
	}
}
