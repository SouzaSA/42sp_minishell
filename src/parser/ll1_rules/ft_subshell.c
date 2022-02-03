/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subshell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:04:12 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/02 21:21:48 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_subshell(t_list **symbol_stack, t_token *token)
{
	t_stk_node	*stk_node;
	t_stk_node	*stk_node_old;

	if (token->tok_type >= 0)
	{
		stk_node_old = ft_lstpop(symbol_stack);
		ft_stk_set_node(&stk_node, stk_node_old, TS_RBRACE);
		ft_lstpush(symbol_stack, stk_node);
		ft_stk_add_child(&stk_node, stk_node_old, token, NTS_AND_OR);
		ft_stk_set_node(&stk_node, stk_node_old, stk_node);
		ft_lstpush(symbol_stack, stk_node);
		ft_stk_set_node(&stk_node, stk_node_old, TS_LBRACE);
		ft_lstpush(symbol_stack, stk_node);
		free(stk_node_old);
	}
}
