/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:18:16 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/18 21:21:54 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int	ft_syntax(t_list *tokens, void	(***tt)(t_list **, enum e_tok_type))
{
	t_list	*symbol_stack;
	void	(*production)(t_list **, enum e_tok_type);
	int		*symbol;
	int		is_valid;

	ft_lstpush(&symbol_stack, ft_new_symbol(TS_EOF));
	ft_lstpush(&symbol_stack, ft_new_symbol(NTS_START));
	is_valid = 1;
	while (is_valid && ft_lstsize(symbol_stack) > 0)
	{
		if (((t_token *)tokens)->tok_type == *((enum e_symbol *)symbol_stack->content))
		{
			tokens->next;
			free(ft_lstpop(symbol_stack));
		}
		else
		{
			symbol = ft_lstpop(symbol_stack);
			production = tt[*symbol][((t_token *)tokens)->tok_type - 20];
			if (production)
				production(tt, ((t_token *)tokens)->tok_type);
			else
				is_valid = 0;
			free(symbol);
		}
	}
	//TODO - Define error criteria and return values.
}
