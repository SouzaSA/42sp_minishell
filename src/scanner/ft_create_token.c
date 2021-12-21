#include "ft_scanner.h"

t_token *ft_create_token(t_scanner *scan, char *str)
{
    char	*nstr;
	t_token	*tok;

	tok = (t_token *)malloc(sizeof(t_token));
	if	(!tok)
        return (NULL);
    ft_memset(tok, 0, sizeof(t_token));
    tok->text_len = strlen(str);
    nstr = (char *)malloc(tok->text_len + 1);
    if(!nstr)
    {
        free(tok);
        return (NULL);
    }
    ft_strcpy(nstr, str);
    tok->text = nstr;
    return (tok);
}
