/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_remove_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 08:12:52 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/13 11:11:53 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

char	*ft_str_remove_quotes(char *str)
{
	char	*unquoted;

	unquoted = NULL;
	if (str)
	{
		if ((str[0] == '\"' || str[0] == '\''))
			unquoted = ft_substr(str, 1, ft_strlen(str) - 2);
		else
			unquoted = ft_strdup(str);
	}
	return (unquoted);
}
