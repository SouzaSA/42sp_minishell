/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:14:58 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/16 17:19:14 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_cmd_redirect_list(t_list **symbol_stack, enum e_tok_type tok_type)
{
	if (tok_type > -1)
	{
		free(ft_lstpop(symbol_stack));
		ft_lstpush(symbol_stack, ft_new_symbol(NTS_REDIRECT_LIST1));
		ft_lstpush(symbol_stack, ft_new_symbol(NTS_IO_REDIRECT));
	}
}

void	ft_cmd_redirect_list1(t_list **symbol_stack, enum e_tok_type tok_type)
{
	if (tok_type > -1)
	{
		free(ft_lstpop(symbol_stack));
		ft_lstpush(symbol_stack, ft_new_symbol(NTS_REDIRECT_LIST));
	}
}
