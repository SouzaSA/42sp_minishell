#include "ft_error.h"

void	ft_parser_error_msg(char *tok_text)
{
	char	*msg;

	msg = ft_strjoin("syntax error near unexpected token ", tok_text);
	ft_put_msg_error(msg, FLAG_ERROR_OWN);
	free (msg);
}
