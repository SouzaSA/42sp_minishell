/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:18:46 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/03 12:26:37 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_io_redirect(t_list **symbol_stack, t_token *token)
{
	t_stk_node	*stk_node;
	t_stk_node	*stk_node_old;

	if (token->tok_type >= 0)
	{
		stk_node_old = ft_lstpop(symbol_stack);
		if (token->tok_type == TS_DLESS)
		{
			ft_stk_set_node(&stk_node, stk_node_old, NTS_IO_HERE);
		}
		else
		{
			ft_stk_set_node(&stk_node, stk_node_old, NTS_IO_FILE);
		}
		ft_lstpush(symbol_stack, stk_node);
		free(stk_node_old);
	}
}
