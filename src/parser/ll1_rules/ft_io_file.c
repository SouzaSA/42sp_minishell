/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:19:26 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/20 09:44:28 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_io_file(t_list **symbol_stack, enum e_symbol tok_type)
{
	if (tok_type >= 0)
	{
		free(ft_lstpop(symbol_stack));
		ft_lstpush(symbol_stack, ft_new_symbol(TS_WORD));
		ft_lstpush(symbol_stack, ft_new_symbol(tok_type));
	}
}
