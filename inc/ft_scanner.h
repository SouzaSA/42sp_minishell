/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanner.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:52:17 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/05 09:18:02 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCANNER_H
# define FT_SCANNER_H
# include "ft_source.h"
# include "libft.h"

/* ************************************************************************** */
/* ---    src      -->  source of input                                   --- */
/* ---    text_len -->  length of token text                              --- */
/* ---    text     -->  token text                                        --- */
/* ************************************************************************** */
typedef struct s_token
{
	t_source	*src;
	int			text_len;
	char		*text;
	int			end_flag;
}	t_token;

typedef struct s_scanner
{
	char	*tok_buf;
	int		tok_bufsize;
	int		tok_bufindex;
}	t_scanner;

void	ft_add_to_buf(t_scanner *scan, char c);
void	free_token(t_token *tok);
t_token	*ft_init_token(void);
t_token	*ft_set_token(t_token *tok, t_source *src, char *str);
t_token	*tokenize(t_scanner *scan, t_source *src);
#endif
