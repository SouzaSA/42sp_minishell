/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:03:04 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/21 08:41:36 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_command(t_list **symbol_stack, enum e_symbol tok_type)
{
	if (tok_type >= 0)
	{
		free(ft_lstpop(symbol_stack));
		if (tok_type == TS_LBRACE)
		{
			ft_lstpush(symbol_stack, ft_new_symbol(NTS_COMMAND1));
			ft_lstpush(symbol_stack, ft_new_symbol(NTS_SUBSHELL));
		}
		else
		{
			ft_lstpush(symbol_stack, ft_new_symbol(NTS_SIMPLE_CMD));
		}
	}
}

void	ft_command1(t_list **symbol_stack, enum e_symbol tok_type)
{
	if (tok_type >= 0)
	{
		free(ft_lstpop(symbol_stack));
		ft_lstpush(symbol_stack, ft_new_symbol(NTS_REDIR_LST));
	}
}
