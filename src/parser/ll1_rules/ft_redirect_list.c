/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:14:58 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/20 10:57:24 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_cmd_redir_list(t_list **symbol_stack, enum e_symbol tok_type)
{
	if (tok_type >= 0)
	{
		free(ft_lstpop(symbol_stack));
		ft_lstpush(symbol_stack, ft_new_symbol(NTS_REDIR_LST1));
		ft_lstpush(symbol_stack, ft_new_symbol(NTS_IO_REDIRECT));
	}
}

void	ft_cmd_redir_list1(t_list **symbol_stack, enum e_symbol tok_type)
{
	if (tok_type >= 0)
	{
		free(ft_lstpop(symbol_stack));
		ft_lstpush(symbol_stack, ft_new_symbol(NTS_REDIR_LST));
	}
}
