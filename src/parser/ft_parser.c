/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:18:16 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/21 19:43:15 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static t_ast	*ft_syntax(t_list *toks, void (***tt)(t_list **, enum e_symbol));
static void		ft_set_source(t_source *src, char *line);

t_ast	*ft_parser(char *line, void	(***tt)(t_list **, enum e_symbol))
{
	t_ast		*ast;
	t_list		*tokens;
	t_source	src;

	ast = NULL;
	ft_set_source(&src, line);
	tokens = ft_lexer(&src);
	ast = ft_syntax(tokens, tt);
	return (ast);
}

static t_ast	*ft_syntax(t_list *toks, void (***tt)(t_list **, enum e_symbol))
{
	t_ast			*ast;
	t_list			*symbol_stack;
	void			(*production)(t_list **, enum e_symbol);
	enum e_symbol	*symbol;
	int				is_valid;

	symbol_stack = NULL;
	ft_lstpush(&symbol_stack, ft_new_symbol(TS_EOF));
	ft_lstpush(&symbol_stack, ft_new_symbol(NTS_START));
	is_valid = 1;
	while (is_valid && ft_lstsize(symbol_stack) > 0)
	{
		symbol = (enum e_symbol *)ft_lsttop(symbol_stack);
		if (((t_token *)toks->content)->tok_type == *symbol)
		{
			toks = toks->next;
			free(ft_lstpop(&symbol_stack));
		}
		else
		{
			//printf("ss: %d token: %d\n", *symbol, ((t_token *)tokens->content)->tok_type);
			production = NULL;
			if (*symbol < NUM_NTS)
				production = tt[*symbol][((t_token *)toks->content)->tok_type - NUM_NTS];
			if (production)
				production(&symbol_stack, ((t_token *)toks->content)->tok_type);
			else
				is_valid = 0;
		}
	}
	if (!is_valid)
		printf("syntax error near unexpected token `%s'\n", ((t_token *)toks->content)->text); //remove
	return (is_valid);
}

static void	ft_set_source(t_source *src, char *line)
{
	src->buffer = ft_strdup(line);
	src->bufsize = ft_strlen(line);
	src->curpos = INIT_SRC_POS;
}
