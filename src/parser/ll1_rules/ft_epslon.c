/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epslon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:56:22 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/30 11:22:02 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_epsilon(t_list **symbol_stack, t_token *token)
{
	if (token->tok_type >= 0)
	{
		free(ft_lstpop(symbol_stack));
	}
}
