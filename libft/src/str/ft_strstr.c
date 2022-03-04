/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:10:45 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/04 18:24:01 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr( char *str, char *substr)
{
	char	*tmp1;
	char	*tmp2;

	tmp2 = substr;
	if (!substr && *substr == '\0')
		return (str);
	while (str && *str != '\0')
	{
		str = ft_strchr(str, *substr);
		tmp1 = str;
		while (*tmp1)
		{
			if (*tmp2 == '\0')
				return (str);
			if (*tmp1++ != *tmp2++)
				break ;
		}
		tmp2 = substr;
		str++;
	}
	return (NULL);
}
