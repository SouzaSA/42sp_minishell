/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subshell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:04:12 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/19 14:28:40 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_subshell(t_list **symbol_stack, enum e_symbol tok_type)
{
	if (tok_type > -1)
	{
		free(ft_lstpop(symbol_stack));
		ft_lstpush(symbol_stack, ft_new_symbol(TS_RBRACE));
		ft_lstpush(symbol_stack, ft_new_symbol(NTS_AND_OR));
		ft_lstpush(symbol_stack, ft_new_symbol(TS_LBRACE));
	}
}
