/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 10:57:23 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/25 15:23:08 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_start(t_syntax *stx_vars, enum e_symbol tok_type)
{
	if (tok_type >= 0)
	{
		free(ft_lstpop(&stx_vars->symbol_stack));
		ft_lstpush(&stx_vars->symbol_stack, ft_stk_node(NTS_AND_OR));
	}
}
