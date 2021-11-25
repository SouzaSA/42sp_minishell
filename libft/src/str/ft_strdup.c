/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 14:11:46 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/19 20:05:07 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dest)
	{
		while (s[i] != '\0')
		{
			dest[i] = s[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}
