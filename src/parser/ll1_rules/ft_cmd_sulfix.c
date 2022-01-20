/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_sulfix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:07:32 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/20 09:43:44 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_cmd_sulfix(t_list **symbol_stack, enum e_symbol tok_type)
{
	if (tok_type >= 0)
	{
		free(ft_lstpop(symbol_stack));
		ft_lstpush(symbol_stack, ft_new_symbol(NTS_SULFIX1));
		if (tok_type == TS_WORD)
		{
			ft_lstpush(symbol_stack, ft_new_symbol(TS_WORD));
		}
		else
		{
			ft_lstpush(symbol_stack, ft_new_symbol(NTS_IO_REDIRECT));
		}
	}
}

void	ft_cmd_sulfix1(t_list **symbol_stack, enum e_symbol tok_type)
{
	if (tok_type >= 0)
	{
		free(ft_lstpop(symbol_stack));
		ft_lstpush(symbol_stack, ft_new_symbol(NTS_SULFIX));
	}
}
