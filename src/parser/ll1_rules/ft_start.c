/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 10:57:23 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/03 18:01:22 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_start(t_list **symbol_stack, enum e_symbol tok_type)
{
	t_stk_node	*stk_node;
	t_stk_node	*stk_node_old;

	if (tok_type >= 0)
	{
		stk_node_old = ft_lstpop(symbol_stack);
		ft_stk_set_node(&stk_node, stk_node_old, NTS_AND_OR);
		ft_lstpush(symbol_stack, stk_node);
		free(stk_node_old);
	}
}
