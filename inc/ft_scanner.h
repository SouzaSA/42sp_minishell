/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanner.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:52:17 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/19 08:38:18 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCANNER_H
# define FT_SCANNER_H
# include "ft_source.h"
# include "libft.h"

enum e_symbol
{
	NTS_START,
	NTS_AND_OR,
	NTS_AND_OR1,
	NTS_PIPELINE,
	NTS_PIPELINE1,
	NTS_COMMAND,
	NTS_COMMAND1,
	NTS_SUBSHELL,
	NTS_SIMPLE_CMD,
	NTS_SIMPLE_CMD1,
	NTS_SIMPLE_CMD2,
	NTS_PREFIX,
	NTS_PREFIX1,
	NTS_SULFIX,
	NTS_SULFIX1,
	NTS_REDIRECT_LIST,
	NTS_REDIRECT_LIST1,
	NTS_IO_REDIRECT,
	NTS_IO_FILE,
	NTS_IO_HERE,
	TS_PIPE,
	TS_LBRACE,
	TS_RBRACE,
	TS_AND_IF,
	TS_OR_IF,
	TS_LESS,
	TS_GREAT,
	TS_DGREAT,
	TS_LESSGREAT,
	TS_DLESS,
	TS_ASSIGNMENT,
	TS_WORD,
	TS_EOF,
	TS_UNKNOWN,
};

/* ************************************************************************** */
/* ---    src      -->  source of input                                   --- */
/* ---    text_len -->  length of token text                              --- */
/* ---    text     -->  token text                                        --- */
/* ************************************************************************** */
typedef struct s_token
{
	enum e_symbol	tok_type;
	t_source		*src;
	int				text_len;
	char			*text;
}	t_token;

typedef struct s_scanner
{
	char		*tok_buf;
	int			tok_bufsize;
	int			tok_bufindex;
}	t_scanner;

void	ft_add_to_buf(t_scanner *scan, char c);
void	ft_del_token(void *tok);
t_token	*ft_init_token(void);
t_list	*ft_lexer(t_source *src);
t_token	*ft_set_token(t_token *tok, t_source *src, char *str);
t_token	*tokenize(t_scanner *scan, t_source *src);
#endif
