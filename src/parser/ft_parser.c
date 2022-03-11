/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:18:16 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/19 11:21:09 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static void		ft_set_source(t_source *src, char *line);

t_ast	*ft_parser(char *line, void (***tt)(t_list **, enum e_symbol))
{
	t_ast		*ast;
	t_list		*tokens;
	t_source	src;

	ast = NULL;
	ft_set_source(&src, line);
	tokens = ft_lexer(&src);
	if (tokens)
	{
		ast = ft_syntax(tokens, tt);
		ft_lstclear(&tokens, &ft_del_token);
	}
	return (ast);
}

static void	ft_set_source(t_source *src, char *line)
{
	src->buffer = ft_strdup(line);
	src->bufsize = ft_strlen(line);
	src->curpos = INIT_SRC_POS;
}
