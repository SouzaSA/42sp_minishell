/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_remove_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 08:12:52 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/11 10:19:41 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

char	*ft_str_remove_quotes(char *str)
{
	char	*unquoted;

	printf("str: %s\n", str);//tirar
	if (str && (str[0] == '\"' || str[0] == '\''))
		unquoted = ft_substr(str, 1, ft_strlen(str) - 2);
	else
		unquoted = ft_strdup(str);
	printf("unquoted: %s\n", unquoted);//tirar
	return (unquoted);
}
