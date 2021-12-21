#include "ft_source.h"
#include "ft_minishell.h"

char	peek_char(t_shell *shell, t_source *src)
{
	long	pos;

	pos = src->curpos;
	if (!src || !src->buffer)
	{
		shell->error_status  = ENODATA;
		return (ERRCHAR);
	}
	if (pos == INIT_SRC_POS)
		pos++;
	pos++;
	if (pos >= src->bufsize)
		return (EOF);
	return (src->buffer[pos]);
}
