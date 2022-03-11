/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:08:06 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/04 08:16:54 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_source.h"

char	ft_next_char(t_source *src)
{
	if (!src || !src->buffer)
	{
		return (ERRCHAR);
	}
	if (src->curpos == INIT_SRC_POS)
		src->curpos = -1;
	if (++src->curpos >= src->bufsize)
	{
		src->curpos = src->bufsize;
		return (EOF);
	}
	return (src->buffer[src->curpos]);
}
