/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:18:46 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/25 15:22:27 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_io_redirect(t_syntax *stx_vars, enum e_symbol tok_type)
{
	if (tok_type >= 0)
	{
		free(ft_lstpop(&stx_vars->symbol_stack));
		if (tok_type == TS_DLESS)
		{
			ft_lstpush(&stx_vars->symbol_stack, ft_stk_node(NTS_IO_HERE));
		}
		else
		{
			ft_lstpush(&stx_vars->symbol_stack, ft_stk_node(NTS_IO_FILE));
		}
	}
}
