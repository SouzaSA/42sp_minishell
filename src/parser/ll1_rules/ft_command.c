/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:03:04 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/25 11:28:10 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_command(t_syntax *stx_vars, enum e_symbol tok_type)
{
	if (tok_type >= 0)
	{
		free(ft_lstpop(&stx_vars->symbol_stack));
		if (tok_type == TS_LBRACE)
		{
			ft_lstpush(&stx_vars->symbol_stack, ft_new_symbol(NTS_COMMAND1));
			ft_lstpush(&stx_vars->symbol_stack, ft_new_symbol(NTS_SUBSHELL));
		}
		else
		{
			ft_lstpush(&stx_vars->symbol_stack, ft_new_symbol(NTS_SIMPLE_CMD));
		}
	}
}

void	ft_command1(t_syntax *stx_vars, enum e_symbol tok_type)
{
	if (tok_type >= 0)
	{
		free(ft_lstpop(&stx_vars->symbol_stack));
		ft_lstpush(&stx_vars->symbol_stack, ft_new_symbol(NTS_REDIR_LST));
	}
}
