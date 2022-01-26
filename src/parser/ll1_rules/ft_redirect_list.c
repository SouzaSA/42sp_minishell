/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:14:58 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/25 15:22:46 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_cmd_redir_list(t_syntax *stx_vars, enum e_symbol tok_type)
{
	if (tok_type >= 0)
	{
		free(ft_lstpop(&stx_vars->symbol_stack));
		ft_lstpush(&stx_vars->symbol_stack, ft_stk_node(NTS_REDIR_LST1));
		ft_lstpush(&stx_vars->symbol_stack, ft_stk_node(NTS_IO_REDIRECT));
	}
}

void	ft_cmd_redir_list1(t_syntax *stx_vars, enum e_symbol tok_type)
{
	if (tok_type >= 0)
	{
		free(ft_lstpop(&stx_vars->symbol_stack));
		ft_lstpush(&stx_vars->symbol_stack, ft_stk_node(NTS_REDIR_LST));
	}
}
