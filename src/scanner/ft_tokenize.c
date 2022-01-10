/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:51:45 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/09 22:26:36 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scanner.h"

static void	ft_create_buff(t_scanner *scan);
static int	ft_token_parse(t_scanner *scan, t_source *src);
static void ft_token_separator(t_scanner *scan, t_source *src, char nc);

t_token	*tokenize(t_scanner *scan, t_source *src)
{
	t_token	*tok;

	tok = ft_init_token();
	if (!src || !src->buffer || !src->bufsize)
	{
		g_errnum = ENODATA;
		return (ft_set_token(tok, src, NULL));
	}
	if (!scan->tok_buf)
		ft_create_buff(scan);
	if (!scan->tok_buf)
		return (ft_set_token(tok, src, NULL));
	scan->tok_bufindex = 0;
	scan->tok_buf[0] = '\0';
	ft_token_parse(scan, src);
	if (scan->tok_bufindex == 0)
		return (ft_set_token(tok, src, NULL));
	if (scan->tok_bufindex >= scan->tok_bufsize)
		scan->tok_bufindex--;
	scan->tok_buf[scan->tok_bufindex] = '\0';
	if (tok)
		ft_set_token(tok, src, scan->tok_buf);
	return (tok);
}

static void	ft_create_buff(t_scanner *scan)
{
	scan->tok_bufsize = 1024;
	scan->tok_buf = malloc(scan->tok_bufsize);
	if (!scan->tok_buf)
	{
		g_errnum = ENOMEM;
		return ;
	}
}

static int	ft_token_parse(t_scanner *scan, t_source *src)
{
	char	nc;

	nc = ft_next_char(src);
	if (nc == ERRCHAR || nc == EOF)
		return (EXIT_FAILURE);
	while (nc != EOF)
	{
		if (nc == ' ' || nc == '\t')
		{
			if (scan->tok_bufindex > 0)
				break ;
		}
		else if (nc == '\n' || nc == '|' || nc == '<' || nc == '>' \
			|| nc == '(' || nc == ')')
		{
			ft_token_separator(scan, src, nc);
			break ;
		}
		else
			ft_add_to_buf(scan, nc);
		nc = ft_next_char(src);
	}
	return (EXIT_SUCCESS);
}

static void ft_token_separator(t_scanner *scan, t_source *src, char nc)
{
	char	nnc;

	if (scan->tok_bufindex == 0 && (nc == '<' || nc == '>'))
	{
		ft_add_to_buf(scan, nc);
		nnc = ft_peek_char(src);
		if ((nc == '<' && (nnc == '>' || nnc == '<')) \
			|| (nc == '>' && nnc == '>'))
		{
			nc = ft_next_char(src);
			ft_add_to_buf(scan, nc);
		}
	}
	else if (scan->tok_bufindex > 0)
		ft_unget_char(src);
	else
		ft_add_to_buf(scan, nc);
}
