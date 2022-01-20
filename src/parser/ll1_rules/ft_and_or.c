/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and_or.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 10:58:53 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/20 09:42:58 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_and_or(t_list **symbol_stack, enum e_symbol tok_type)
{
	if (tok_type >= 0)
	{
		free(ft_lstpop(symbol_stack));
		ft_lstpush(symbol_stack, ft_new_symbol(NTS_AND_OR1));
		ft_lstpush(symbol_stack, ft_new_symbol(NTS_PIPELINE));
	}
}

void	ft_and_or1(t_list **symbol_stack, enum e_symbol tok_type)
{
	if (tok_type >= 0)
	{
		free(ft_lstpop(symbol_stack));
		ft_lstpush(symbol_stack, ft_new_symbol(NTS_AND_OR));
		ft_lstpush(symbol_stack, ft_new_symbol(tok_type));
	}
}
