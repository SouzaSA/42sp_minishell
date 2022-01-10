/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:51:29 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/09 12:21:37 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scanner.h"

static void ft_set_token_type(t_token *tok, char *str);

t_token	*ft_set_token(t_token *tok, t_source *src, char *str)
{
	char	*nstr;

	if (!str)
	{
		tok->tok_type = TOK_EOF;
		return (tok);
	}
	tok->text_len = strlen(str);
	nstr = ft_strdup(str);
	if (!nstr)
	{
		ft_put_msg_error("scanner: failed to alloc buffer", FLAG_ERROR_P);
		tok->tok_type = TOK_EOF;
		return (tok);
	}
	ft_set_token_type(tok, str);
	tok->text = nstr;
	tok->src = src;
	return (tok);
}

static void ft_set_token_type(t_token *tok, char *str)
{
	if (ft_strcmp(str, "|") == 0)
		tok->tok_type = PIPE;
	else if (ft_strcmp(str, "(") == 0)
		tok->tok_type = LBRACE;
	else if (ft_strcmp(str, ")") == 0)
		tok->tok_type = RBRACE;
	else if (ft_strcmp(str, "&&") == 0)
		tok->tok_type = AND_IF;
	else if (ft_strcmp(str, "||") == 0)
		tok->tok_type = OR_IF;
	else if (ft_strcmp(str, "<") == 0)
		tok->tok_type = LESS;
	else if (ft_strcmp(str, ">") == 0)
		tok->tok_type = GREAT;
	else if (ft_strcmp(str, ">>") == 0)
		tok->tok_type = DGREAT;
	else if (ft_strcmp(str, "<>") == 0)
		tok->tok_type = LESSGREAT;
	else if (ft_strcmp(str, "<<") == 0)
		tok->tok_type = DLESS;
	else if (ft_strcmp(str, "\n") == 0)
		tok->tok_type = NEW_LINE;
	else if (ft_strchr(str, '=') && !ft_isdigit(str[0]))
		tok->tok_type = ASSIGNMENT;
	else
		tok->tok_type = WORD;
}