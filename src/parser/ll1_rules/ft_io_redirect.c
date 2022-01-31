/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:18:46 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/30 11:26:34 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_io_redirect(t_list **symbol_stack, t_token *token)
{
	if (token->tok_type >= 0)
	{
		free(ft_lstpop(symbol_stack));
		if (token->tok_type == TS_DLESS)
		{
			ft_lstpush(symbol_stack, ft_stk_node(NTS_IO_HERE));
		}
		else
		{
			ft_lstpush(symbol_stack, ft_stk_node(NTS_IO_FILE));
		}
	}
}
