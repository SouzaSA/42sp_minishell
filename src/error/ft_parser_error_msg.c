#include "ft_error.h"

void	ft_parser_error_msg(char *tok_text)
{
	char	*msg;
	char	*aux;

	if (!tok_text)
	{
		msg = "syntax error near unexpected token `\\n´";
		ft_put_msg_error(msg, FLAG_ERROR_OWN);
		return ;
	}
	aux = ft_strjoin("syntax error near unexpected token `", tok_text);
	msg = ft_strjoin(aux, "´");
	free(aux);
	ft_put_msg_error(msg, FLAG_ERROR_OWN);
	free (msg);
}
