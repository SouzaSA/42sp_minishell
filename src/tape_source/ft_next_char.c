/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:08:06 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/21 21:08:08 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_source.h"
#include "ft_minishell.h"

char	ft_next_char(t_source *src)
{
	char	tmp_char;

	tmp_char = 0;
	if (!src || !src->buffer)
	{
		g_errnum = ENODATA;
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
