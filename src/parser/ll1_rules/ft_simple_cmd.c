/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:05:20 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/25 11:32:08 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_simple_cmd(t_syntax *stx_vars, enum e_symbol tok_type)
{
	if (tok_type >= 0)
	{
		free(ft_lstpop(&stx_vars->symbol_stack));
		if (tok_type == TS_WORD)
		{
			ft_lstpush(&stx_vars->symbol_stack, ft_new_symbol(NTS_SIMPLE_CMD2));
			ft_lstpush(&stx_vars->symbol_stack, ft_new_symbol(TS_WORD));
		}
		else
		{
			ft_lstpush(&stx_vars->symbol_stack, ft_new_symbol(NTS_SIMPLE_CMD1));
			ft_lstpush(&stx_vars->symbol_stack, ft_new_symbol(NTS_PREFIX));
		}
	}
}

void	ft_simple_cmd1(t_syntax *stx_vars, enum e_symbol tok_type)
{
	if (tok_type >= 0)
	{
		free(ft_lstpop(&stx_vars->symbol_stack));
		ft_lstpush(&stx_vars->symbol_stack, ft_new_symbol(NTS_SIMPLE_CMD2));
		ft_lstpush(&stx_vars->symbol_stack, ft_new_symbol(TS_WORD));
	}
}

void	ft_simple_cmd2(t_syntax *stx_vars, enum e_symbol tok_type)
{
	if (tok_type >= 0)
	{
		free(ft_lstpop(&stx_vars->symbol_stack));
		ft_lstpush(&stx_vars->symbol_stack, ft_new_symbol(NTS_SULFIX));
	}
}
