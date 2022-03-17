/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_source.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 08:28:08 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/17 14:31:00 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SOURCE_H
# define FT_SOURCE_H
# include "ft_error.h"

# define ERRCHAR 0
# define INIT_SRC_POS -2

/* ************************************************************************** */
/* ---    buffer --> input text                                           --- */
/* ---    bufsize --> size of the input text                              --- */
/* ---    curpos --> absolute char position in source                     --- */
/* ************************************************************************** */
typedef struct s_source
{
	char	*buffer;
	long	bufsize;
	long	curpos;
}	t_source;

char	ft_next_char(t_source *src);
char	ft_peek_char(t_source *src);
void	ft_skip_white_spaces(t_source *src);
void	ft_unget_char(t_source *src);
#endif
