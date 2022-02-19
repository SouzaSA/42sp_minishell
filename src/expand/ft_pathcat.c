/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:12:10 by edpaulin          #+#    #+#             */
/*   Updated: 2022/02/16 17:17:13 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

char	*ft_pathcat(char *path, char *file)
{
	size_t	last_char;
	char	*new_path;
	char	*tmp;

	if (!path || !file)
		return (NULL);
	last_char = (ft_strlen(path) - 1);
	if (path[last_char] == '/')
		return (ft_strjoin(path, file));
	tmp = ft_strjoin(path, "/");
	if (!tmp)
		return (NULL);
	new_path = ft_strjoin(tmp, file);
	free(tmp);
	return (new_path);
}
