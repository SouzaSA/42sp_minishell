/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_sulfix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:07:32 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/25 15:21:36 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_cmd_sulfix(t_syntax *stx_vars, enum e_symbol tok_type)
{
	if (tok_type >= 0)
	{
		free(ft_lstpop(&stx_vars->symbol_stack));
		ft_lstpush(&stx_vars->symbol_stack, ft_stk_node(NTS_SULFIX1));
		if (tok_type == TS_WORD)
		{
			ft_lstpush(&stx_vars->symbol_stack, ft_stk_node(TS_WORD));
		}
		else
		{
			ft_lstpush(&stx_vars->symbol_stack, ft_stk_node(NTS_IO_REDIRECT));
		}
	}
}

void	ft_cmd_sulfix1(t_syntax *stx_vars, enum e_symbol tok_type)
{
	if (tok_type >= 0)
	{
		free(ft_lstpop(&stx_vars->symbol_stack));
		ft_lstpush(&stx_vars->symbol_stack, ft_stk_node(NTS_SULFIX));
	}
}
