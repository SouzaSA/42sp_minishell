#ifndef FT_SCANNER_H
# define FT_SCANNER_H
# include "ft_source.h"
# include "libft.h"

/* ************************************************************************** */
/* ---    src      -->  source of input                                   --- */
/* ---    text_len -->  length of token text                              --- */
/* ---    text     -->  token text                                        --- */
/* ************************************************************************** */
typedef struct	s_token
{
	t_source	*src;
	int			text_len;
	char		*text;
}	t_token;

typedef struct	s_scanner
{
	char	*tok_buf;
	int		tok_bufsize;
	int		tok_bufindex;
	int		end_flag;
}	t_scanner;

/* the special EOF token, which indicates the end of input */
extern struct token_s eof_token;///lawstma

t_token	*ft_tokenize(t_source *src);
void	ft_free_token(t_token *tok);
#endif
