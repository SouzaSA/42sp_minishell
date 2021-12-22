#include "ft_scanner.h"

void	ft_add_to_buf(t_scanner *scan, char c)
{
    char	*tmp;

    scan->tok_buf[scan->tok_bufindex++] = c;
    if(scan->tok_bufindex >= scan->tok_bufsize)
    {

		*tmp = realloc(scan->tok_buf, scan->tok_bufsize*2);
        if(!tmp)
        {
            g_errnum = ENOMEM;
            return;
        }
        scan->tok_buf = tmp;
        scan->tok_bufsize *= 2;
    }
}
