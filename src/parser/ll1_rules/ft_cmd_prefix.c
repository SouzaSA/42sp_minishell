/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_prefix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:06:32 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/19 08:48:34 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_cmd_prefix(t_list **symbol_stack, enum e_symbol tok_type)
{
	if (tok_type > -1)
	{
		free(ft_lstpop(symbol_stack));
		ft_lstpush(symbol_stack, ft_new_symbol(NTS_PREFIX1));
		if (tok_type == TS_ASSIGNMENT)
		{
			ft_lstpush(symbol_stack, ft_new_symbol(TS_ASSIGNMENT));
		}
		else
		{
			ft_lstpush(symbol_stack, ft_new_symbol(NTS_IO_REDIRECT));
		}
	}
}

void	ft_cmd_prefix1(t_list **symbol_stack, enum e_symbol tok_type)
{
	free(ft_lstpop(symbol_stack));
	ft_lstpush(symbol_stack, ft_new_symbol(NTS_PREFIX));
}
