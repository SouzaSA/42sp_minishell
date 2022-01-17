/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io_here.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:20:44 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/16 17:49:10 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_io_here(t_list **symbol_stack, enum e_tok_type tok_type)
{
	if (tok_type > -1)
	{
		free(ft_lstpop(symbol_stack));
		ft_lstpush(symbol_stack, ft_new_symbol(TS_WORD));
		ft_lstpush(symbol_stack, ft_new_symbol(TS_DLESS));
	}
}
