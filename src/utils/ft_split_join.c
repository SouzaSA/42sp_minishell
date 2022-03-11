/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:18:35 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/11 10:59:48 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

char	*ft_split_join(char **splitted)
{
	int		i;
	char	*aux;
	char	*new;

	i = 0;
	new = ft_strdup("");
	while (splitted[i])
	{
		aux = new;
		new = ft_strjoin(new, splitted[i]);
		free(aux);
		i++;
	}
	return (new);
}
