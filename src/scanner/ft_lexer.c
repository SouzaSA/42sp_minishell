/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 09:50:00 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/09 21:09:40 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scanner.h"
#include <stdio.h> //tirar

static void ft_init_scan(t_scanner *scan);

//teste
static void ft_token_print(void *token)
{
	if (((t_token *)token)->tok_type != TOK_EOF)
		printf("%s, %d\n", ((t_token *)token)->text, ((t_token *)token)->tok_type);
}

t_list *ft_lexer(t_source *src)
{
	t_scanner	scan;
	t_token		*tok;
	t_list		*token_list;

	ft_init_scan(&scan);
	tok = tokenize(&scan, src);
	token_list = NULL;
	while (tok->tok_type != TOK_EOF)
	{
		ft_lstadd_back(&token_list, ft_lstnew(tok));
		tok = tokenize(&scan, src);
	}
	ft_lstadd_back(&token_list, ft_lstnew(tok));

	ft_lstiter(token_list, &ft_token_print);
	free(scan.tok_buf);
	return (token_list);
}

static void ft_init_scan(t_scanner *scan)
{
	scan->tok_buf = NULL;
	scan->tok_bufsize = 0;
	scan->tok_bufindex = -1;
}
