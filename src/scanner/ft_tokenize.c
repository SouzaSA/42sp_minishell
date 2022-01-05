/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:51:45 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/05 09:19:40 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scanner.h"

static void	ft_int_buff(t_scanner *scan);
static void	ft_token_parse(t_scanner *scan, t_source *src, char nc);

t_token	*tokenize(t_scanner *scan, t_source *src)
{
	char	nc;
	t_token	*tok;

	tok = ft_init_token();
	if (!src || !src->buffer || !src->bufsize)
	{
		g_errnum = ENODATA;
		return (tok);
	}
	if (!scan->tok_buf)
		ft_int_buff(scan);
	if (!scan->tok_buf)
		return (tok);
	nc = ft_next_char(src);
	ft_token_parse(scan, src, ft_next_char(src));
	if (scan->tok_bufindex == 0)
		return (tok);
	if (scan->tok_bufindex >= scan->tok_bufsize)
		scan->tok_bufindex--;
	scan->tok_buf[scan->tok_bufindex] = '\0';
	if (tok)
		ft_set_token(tok, src, scan->tok_buf);
	return (tok);
}

static void	ft_int_buff(t_scanner *scan)
{
	scan->tok_bufsize = 1024;
	scan->tok_buf = malloc(scan->tok_bufsize);
	if (!scan->tok_buf)
	{
		g_errnum = ENOMEM;
		return ;
	}
	scan->tok_bufindex = 0;
	scan->tok_buf[0] = '\0';
}

static void	ft_token_parse(t_scanner *scan, t_source *src, char nc)
{
	int	endloop;

	endloop = 0;
	if (nc == ERRCHAR || nc == EOF)
		return ;
	while (nc != EOF && !endloop)
	{
		if (nc == ' ' || nc == '\t')
			endloop = 1;
		else if (nc == '\n')
		{
			if (scan->tok_bufindex > 0)
				ft_unget_char(src);
			else
				ft_add_to_buf(scan, nc);
			endloop = 1;
		}
		else
			ft_add_to_buf(scan, nc);
		if (!endloop)
			nc = ft_next_char(src);
	}
}
