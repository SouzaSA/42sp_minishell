/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:10:45 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/04 18:28:20 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr( char *str, char *substr)
{
	char	*pos;

	if (!str || !substr)
		return (NULL);
	pos = ft_strchr(str, substr[0]);
	while (pos && ft_strncmp(pos, substr, ft_strlen(substr)))
		pos = ft_strchr(pos + 1, substr[0]);
	if (!pos)
		return (NULL);
	return (pos);
}
