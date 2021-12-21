#include "ft_source.h"
#include "ft_minishell.h"

char	ft_next_char(t_shell *shell, t_source *src)
{
	char	tmp_char;

	tmp_char = 0;
	if (!src || !src->buffer)
	{
		shell->error_status = ENODATA;
		return (ERRCHAR);
	}
	if (src->curpos == INIT_SRC_POS)
		src->curpos  = -1;
	else
		tmp_char = src->buffer[src->curpos];
	if (++src->curpos >= src->bufsize)
	{
		src->curpos = src->bufsize;
		return (EOF);
	}
	return (src->buffer[src->curpos]);
}
