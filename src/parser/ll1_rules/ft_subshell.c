/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subshell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:04:12 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/30 11:32:08 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_subshell(t_list **symbol_stack, t_token *token)
{
	if (token->tok_type >= 0)
	{
		free(ft_lstpop(symbol_stack));
		ft_lstpush(symbol_stack, ft_stk_node(TS_RBRACE));
		ft_lstpush(symbol_stack, ft_stk_node(NTS_AND_OR));
		ft_lstpush(symbol_stack, ft_stk_node(TS_LBRACE));
	}
}
