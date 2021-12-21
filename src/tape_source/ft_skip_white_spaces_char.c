#include "ft_source.h"

void	ft_skip_white_spaces(t_source *src)
{
	char	c;

	if(!src || !src->buffer)
		return ;
	c = peek_char(src);
	while((c != EOF) && (ft_isspace((int)c)))
		next_char(src);
}
