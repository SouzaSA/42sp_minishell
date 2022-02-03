/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_sulfix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:07:32 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/03 17:56:04 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_cmd_sulfix(t_list **symbol_stack, enum e_symbol tok_type)
{
	t_stk_node	*stk_node;
	t_stk_node	*stk_node_old;

	if (tok_type >= 0)
	{
		stk_node_old = (t_stk_node *)ft_lstpop(symbol_stack);
		ft_stk_set_node(&stk_node, stk_node_old, NTS_SULFIX1);
		ft_lstpush(symbol_stack, stk_node);
		if (tok_type == TS_WORD)
		{
			ft_stk_set_node(&stk_node, stk_node_old, TS_WORD);
			stk_node->ast_type = AST_CMD;
		}
		else
		{
			ft_stk_set_node(&stk_node, stk_node_old, NTS_IO_REDIRECT);
		}
		ft_lstpush(symbol_stack, stk_node);
		free(stk_node_old);
	}
}

void	ft_cmd_sulfix1(t_list **symbol_stack, enum e_symbol tok_type)
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
