/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_buff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:51:19 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/04 08:16:14 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scanner.h"

static char	*ft_expand_mem(void *old_ptr, int old_size, int new_size);

void	ft_add_to_buf(t_scanner *scan, char c)
{
	char	*tmp;

	tmp = NULL;
	scan->tok_buf[scan->tok_bufindex++] = c;
	if (scan->tok_bufindex >= scan->tok_bufsize)
	{
		tmp = ft_expand_mem(tmp, scan->tok_bufsize, scan->tok_bufsize * 2);
		if (!tmp)
		{
			return ;
		}
		scan->tok_buf = tmp;
		scan->tok_bufsize *= 2;
	}
}

static char	*ft_expand_mem(void *old_ptr, int old_size, int new_size)
{
	void	*new_ptr;

	new_ptr = NULL;
	if (new_size > old_size)
	{
		new_ptr = malloc(new_size);
		if (!new_ptr)
		{
			return (NULL);
		}
		if (old_ptr)
		{
			ft_memcpy(new_ptr, old_ptr, old_size);
			free(old_ptr);
		}
	}
	else
	{
		new_ptr = old_ptr;
	}
	return (new_ptr);
}
