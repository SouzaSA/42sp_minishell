/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:18:16 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/19 09:53:47 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int	ft_syntax(t_list *tokens, void	(***tt)(t_list **, enum e_symbol))
{
	t_list	*symbol_stack;
	void	(*production)(t_list **, enum e_symbol);
	int		*symbol;
	int		is_valid;

	ft_lstpush(&symbol_stack, ft_new_symbol(TS_EOF));
	ft_lstpush(&symbol_stack, ft_new_symbol(NTS_START));
	is_valid = 1;
	while (is_valid && ft_lstsize(symbol_stack) > 0)
	{
		symbol = (enum e_symbol *)ft_lsttop(symbol_stack);
		if (((t_token *)tokens)->tok_type == *symbol)
		{
			tokens->next;
			free(ft_lstpop(symbol_stack));
		}
		else
		{
			production = tt[*symbol][((t_token *)tokens)->tok_type - 20];
			if (production)
				production(tt, ((t_token *)tokens)->tok_type);
			else
				is_valid = 0;
		}
	}
	//TODO - Define error criteria and return values.
}
