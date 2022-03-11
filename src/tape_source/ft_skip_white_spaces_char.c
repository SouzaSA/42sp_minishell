/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_white_spaces_char.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:08:29 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/06 11:09:29 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_source.h"

void	ft_skip_white_spaces(t_source *src)
{
	char	c;

	if (!src || !src->buffer)
		return ;
	c = ft_peek_char(src);
	while (c != EOF && (c == ' ' || c == '\t'))
		ft_next_char(src);
}
