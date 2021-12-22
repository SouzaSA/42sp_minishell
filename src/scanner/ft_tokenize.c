/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:51:45 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/22 19:37:56 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scanner.h"

static void		ft_int_buff(t_scanner *scan);
static void		ft_token_parse(t_scanner *scan, t_source *src, char nc);
static t_token	*ft_set_token(t_scanner *scan, t_source *src);

t_token	*tokenize(t_scanner *scan, t_source *src)
{
	char	nc;

	if (!src || !src->buffer || !src->bufsize)
	{
		g_errnum = ENODATA;
		scan->end_flag = 1;
		return (NULL);
	}
	if (!scan->tok_buf)
		ft_int_buff(scan);
	if (!scan->tok_buf)
		return (NULL);
	nc = ft_next_char(src);
	ft_token_parse(scan, src, ft_next_char(src));
	if (scan->tok_bufindex == 0)
	{
		scan->end_flag = 1;
		return (NULL);
	}
	if (scan->tok_bufindex >= scan->tok_bufsize)
		scan->tok_bufindex--;
	scan->tok_buf[scan->tok_bufindex] = '\0';
	return (ft_set_token(scan, src));
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
	scan->end_flag = 0;
	scan->tok_buf[0] = '\0';
}

static void	ft_token_parse(t_scanner *scan, t_source *src, char nc)
{
	int	endloop;

	endloop = 0;
	if (nc == ERRCHAR || nc == EOF)
	{
		scan->end_flag = 1;
		return ;
	}
	while (nc != EOF && !endloop)
	{
		if (nc == ' ' || nc == '\t')
			endloop = 1;
		else if (nc == '\n')
		{
			if (scan->tok_bufindex > 0)
				ft_unget_char(src);
			else
				ft_add_to_buf(nc);
			endloop = 1;
		}
		else
			ft_add_to_buf(nc);
		if (!endloop)
			nc = ft_next_char(src);
	}
}

static t_token	*ft_set_token(t_scanner *scan, t_source *src)
{
	t_token	*tok;

	tok = create_token(scan->tok_buf);
	if (!tok)
	{
		ft_put_msg_error("scanner: failed to alloc buffer", FLAG_ERROR_P);
		scan->end_flag = 1;
		return (tok);
	}
	tok->src = src;
	return (tok);
}
