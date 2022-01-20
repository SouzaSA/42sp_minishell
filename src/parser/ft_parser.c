/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:18:16 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/20 11:54:25 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static int	ft_syntax(t_list *tokens, void	**(*tt)(t_list **, enum e_symbol));
static void	ft_set_source(t_source *src, char *line);

int	ft_parser(char *line, void	**(*tt)(t_list **, enum e_symbol))
{
	t_list		*tokens;
	t_source	src;
	int			is_valid;

	ft_set_source(&src, line);
	tokens = ft_lexer(&src);
	is_valid = ft_syntax(tokens, tt);
	return (is_valid);
}

static int	ft_syntax(t_list *tokens, void	**(*tt)(t_list **, enum e_symbol))
{
	t_list			*symbol_stack;
	void			(*production)(t_list **, enum e_symbol);
	enum e_symbol	*symbol;
	int				is_valid;

	ft_lstpush(&symbol_stack, ft_new_symbol(TS_EOF));
	ft_lstpush(&symbol_stack, ft_new_symbol(NTS_START));
	is_valid = 1;
	while (is_valid && ft_lstsize(symbol_stack) > 0)
	{
		symbol = (enum e_symbol *)ft_lsttop(symbol_stack);
		if (((t_token *)tokens)->tok_type == *symbol)
		{
			tokens = tokens->next;
			free(ft_lstpop(&symbol_stack));
		}
		else
		{
			production = tt[*symbol][((t_token *)tokens)->tok_type - 20];
			if (production)
				production(&symbol_stack, ((t_token *)tokens)->tok_type);
			else
				is_valid = 0;
		}
	}
	return (is_valid);
}

static void	ft_set_source(t_source *src, char *line)
{
	src->buffer = ft_strdup(line);
	src->bufsize = ft_strlen(line);
	src->curpos = INIT_SRC_POS;
}
