/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 09:50:00 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/16 08:35:39 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scanner.h"
#include <stdio.h> //tirar

static void	ft_init_scan(t_scanner *scan);

t_list	*ft_lexer(t_source *src)
{
	t_scanner	scan;
	t_token		*tok;
	t_list		*token_list;

	ft_init_scan(&scan);
	tok = tokenize(&scan, src);
	token_list = NULL;
	while (tok->tok_type != TS_EOF)
	{
		ft_lstadd_back(&token_list, ft_lstnew(tok));
		tok = tokenize(&scan, src);
	}
	ft_lstadd_back(&token_list, ft_lstnew(tok));
	free(scan.tok_buf);
	return (token_list);
}

static void	ft_init_scan(t_scanner *scan)
{
	scan->tok_buf = NULL;
	scan->tok_bufsize = 0;
	scan->tok_bufindex = -1;
}
