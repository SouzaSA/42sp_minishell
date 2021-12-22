#include "ft_scanner.h"

t_token *tokenize(t_scanner *scan, t_source *src)
{
	int		endloop;
	char	nc;
	t_token	*tok;

	endloop = 0;
	if(!src || !src->buffer || !src->bufsize)
	{
		g_errnum = ENODATA;
		return &eof_token;
	}
	if(!scan->tok_buf)
	{
		scan->tok_bufsize = 1024;
		scan->tok_buf = malloc(scan->tok_bufsize);
		if(!scan->tok_buf)
		{
			g_errnum = ENOMEM;
			return &eof_token;
		}
	}
	scan->tok_bufindex = 0;
	scan->tok_buf[0] = '\0';
	nc = next_char(src);
	ft_token_parse(scan, src, ft_next_char(src));
    if(scan->tok_bufindex == 0)
    {
        return &eof_token;
    }

    if(scan->tok_bufindex >= scan->tok_bufsize)
    {
        scan->tok_bufindex--;
    }
    scan->tok_buf[scan->tok_bufindex] = '\0';
	tok = create_token(scan->tok_buf);
    if(!tok)
    {
        fprintf(stderr, "error: failed to alloc buffer: %s\n",
                strerror(errno));
        return &eof_token;
    }
    tok->src = src;
    return tok;
}

static void	ft_token_parse(t_scanner *scan, t_source *src, char nc)
{
	int	endloop;

	endloop = 0;
	if(nc == ERRCHAR || nc == EOF)
	{
		scan->end_flag = 1;
		return ;
	}
	while(nc != EOF)
	{
		if (nc == ' ' || nc == '\t')
			endloop = 1;
		else if (nc == '\n')
		{
			if(scan->tok_bufindex > 0)
				ft_unget_char(src);
			else
				ft_add_to_buf(nc);
			endloop = 1;
		}
		else
			ft_add_to_buf(nc);
		if(endloop)
			break ;
		nc = ft_next_char(src);
	}
}
