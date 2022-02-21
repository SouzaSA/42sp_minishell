/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 09:50:00 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/20 13:49:53 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scanner.h"
#include <stdio.h> //tirar

static void		ft_init_scan(t_scanner *scan);
static t_list	*ft_mk_token_lst(t_scanner *scan, t_source *src);
static int		ft_check_balanced_quotes(char *str);

t_list	*ft_lexer(t_source *src)
{
	t_scanner	scan;
	t_list		*token_list;

	ft_init_scan(&scan);
	token_list = ft_mk_token_lst(&scan, src);
	free(scan.tok_buf);
	return (token_list);
}

static void	ft_init_scan(t_scanner *scan)
{
	scan->tok_buf = NULL;
	scan->tok_bufsize = 0;
	scan->tok_bufindex = -1;
}

static t_list	*ft_mk_token_lst(t_scanner *scan, t_source *src)
{
	int		is_balanced;
	int		cmd_flag;
	t_token	*tok;
	t_list	*token_list;

	is_balanced = 1;
	cmd_flag = 0;
	tok = tokenize(scan, src);
	token_list = NULL;
	while (tok->type != TS_EOF)
	{
		if (is_balanced)
			is_balanced = ft_check_balanced_quotes(tok->text);
		if (tok->type == TS_WORD)
			cmd_flag = 1;
		if (tok->type == TS_AND || tok->type == TS_OR || tok->type == TS_PIPE)
			cmd_flag = 0;
		if (tok->type == TS_ASSIGNMENT && cmd_flag)
			tok->type = TS_WORD;
		ft_lstadd_back(&token_list, ft_lstnew(tok));
		tok = tokenize(scan, src);
	}
	ft_lstadd_back(&token_list, ft_lstnew(tok));
	if (!is_balanced)
		ft_lstclear(&token_list, &ft_del_token);
	return (token_list);
}

static int	ft_check_balanced_quotes(char *str)
{
	int	is_balanced;
	int	last_idx;

	is_balanced = 1;
	if (str)
	{
		last_idx = ft_strlen(str) - 1;
		if ((str[0] == '\'' && str[last_idx] != '\'' ) \
			|| (str[0] == '\"' && str[last_idx] != '\"'))
		{
			is_balanced = 0;
			ft_put_msg_error("lexer: unbalanced quotes", FLAG_ERROR_OWN);
		}
	}
	return (is_balanced);
}
