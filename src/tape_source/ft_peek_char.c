/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_peek_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:08:19 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/21 21:08:22 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_source.h"
#include "ft_minishell.h"

char	ft_peek_char(t_source *src)
{
	long	pos;

	pos = src->curpos;
	if (!src || !src->buffer)
	{
		g_errnum = ENODATA;
		return (ERRCHAR);
	}
	if (pos == INIT_SRC_POS)
		pos++;
	pos++;
	if (pos >= src->bufsize)
		return (EOF);
	return (src->buffer[pos]);
}
