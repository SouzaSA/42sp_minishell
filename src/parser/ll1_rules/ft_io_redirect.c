/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:18:46 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/20 09:44:43 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_io_redirect(t_list **symbol_stack, enum e_symbol tok_type)
{
	if (tok_type >= 0)
	{
		free(ft_lstpop(symbol_stack));
		if (tok_type == TS_DLESS)
		{
			ft_lstpush(symbol_stack, ft_new_symbol(NTS_IO_HERE));
		}
		else
		{
			ft_lstpush(symbol_stack, ft_new_symbol(NTS_IO_FILE));
		}
	}
}
