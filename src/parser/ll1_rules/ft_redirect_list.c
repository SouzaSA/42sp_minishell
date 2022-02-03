/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:14:58 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/03 12:24:25 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_cmd_redir_list(t_list **symbol_stack, t_token *token)
{
	t_stk_node	*stk_node;
	t_stk_node	*stk_node_old;

	if (token->tok_type >= 0)
	{
		stk_node_old = ft_lstpop(symbol_stack);
		ft_stk_set_node(&stk_node, stk_node_old, NTS_REDIR_LST1);
		ft_lstpush(symbol_stack, stk_node);
		ft_stk_set_node(&stk_node, stk_node_old, NTS_IO_REDIRECT);
		ft_lstpush(symbol_stack, stk_node);
		free(stk_node_old);
	}
}

void	ft_cmd_redir_list1(t_list **symbol_stack, t_token *token)
{
	t_stk_node	*stk_node;
	t_stk_node	*stk_node_old;

	if (token->tok_type >= 0)
	{
		stk_node_old = ft_lstpop(symbol_stack);
		ft_stk_set_node(&stk_node, stk_node_old, NTS_REDIR_LST);
		ft_lstpush(symbol_stack, stk_node);
		free(stk_node_old);
	}
}
