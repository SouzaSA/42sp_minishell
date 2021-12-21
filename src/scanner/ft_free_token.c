#include "ft_scanner.h"

void	free_token(t_token *tok)
{
    if(tok->text)
        free(tok->text);
    free(tok);
}
