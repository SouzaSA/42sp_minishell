/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:26:30 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/02 18:28:16 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

char	*ft_pathcat(char *path_buffer, char *path)
{
	char	*cat;
	char	*aux;

	if (path_buffer[ft_strlen(path_buffer) - 1] == '/')
		cat = ft_strjoin(path_buffer, path);
	else
	{
		aux = ft_strjoin(path_buffer, "/");
		cat = ft_strjoin(aux, path);
		if (aux)
			free(aux);
	}
	return (cat);
}
