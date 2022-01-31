/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_prefix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:06:32 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/30 11:10:06 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_cmd_prefix(t_list **symbol_stack, t_token *token)
{
	if (token->tok_type >= 0)
	{
		free(ft_lstpop(symbol_stack));
		ft_lstpush(symbol_stack, ft_stk_node(NTS_PREFIX1));
		if (token->tok_type == TS_ASSIGNMENT)
		{
			ft_lstpush(symbol_stack, ft_stk_node(TS_ASSIGNMENT));
		}
		else
		{
			ft_lstpush(symbol_stack, ft_stk_node(NTS_IO_REDIRECT));
		}
	}
}

void	ft_cmd_prefix1(t_list **symbol_stack, t_token *token)
{
	if (token->tok_type >= 0)
	{
		free(ft_lstpop(symbol_stack));
		ft_lstpush(symbol_stack, ft_stk_node(NTS_PREFIX));
	}
}
