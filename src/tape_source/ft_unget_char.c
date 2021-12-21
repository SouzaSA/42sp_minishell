#include "ft_source.h"

void	ft_unget_char(t_source *src)
{
	if(src->curpos < 0)
		return ;
	src->curpos--;
}
