/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:51:29 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/16 08:37:07 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scanner.h"

static void	ft_set_token_type(t_token *tok, char *str);

t_token	*ft_set_token(t_token *tok, t_source *src, char *str)
{
	char	*nstr;

	if (!str)
	{
		tok->tok_type = TS_EOF;
		if (src && src->buffer)
			free(src->buffer);
		return (tok);
	}
	tok->text_len = strlen(str);
	nstr = ft_strdup(str);
	if (!nstr)
	{
		ft_put_msg_error("scanner: failed to alloc buffer", FLAG_ERROR_P);
		tok->tok_type = TS_EOF;
		return (tok);
	}
	ft_set_token_type(tok, str);
	tok->text = nstr;
	tok->src = src;
	return (tok);
}

static void	ft_set_token_type(t_token *tok, char *str)
{
	if (ft_strcmp(str, "|") == 0)
		tok->tok_type = TS_PIPE;
	else if (ft_strcmp(str, "(") == 0)
		tok->tok_type = TS_LBRACE;
	else if (ft_strcmp(str, ")") == 0)
		tok->tok_type = TS_RBRACE;
	else if (ft_strcmp(str, "&&") == 0)
		tok->tok_type = TS_AND_IF;
	else if (ft_strcmp(str, "||") == 0)
		tok->tok_type = TS_OR_IF;
	else if (ft_strcmp(str, "<") == 0)
		tok->tok_type = TS_LESS;
	else if (ft_strcmp(str, ">") == 0)
		tok->tok_type = TS_GREAT;
	else if (ft_strcmp(str, ">>") == 0)
		tok->tok_type = TS_DGREAT;
	else if (ft_strcmp(str, "<>") == 0)
		tok->tok_type = TS_LESSGREAT;
	else if (ft_strcmp(str, "<<") == 0)
		tok->tok_type = TS_DLESS;
	else if (ft_strchr(str, '=') && !ft_isdigit(str[0]))
		tok->tok_type = TS_ASSIGNMENT;
	else
		tok->tok_type = TS_WORD;
}
