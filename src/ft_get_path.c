/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:55:56 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/30 15:56:11 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	**ft_get_path(char **envp)
{
	int		i;
	char	*str;
	char	**path;

	i = 0;
	str = NULL;
	path = NULL;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			str = ft_strdup(envp[i] + 5);
		i++;
	}
	if (str)
	{
		path = ft_split(str, ':');
		free(str);
	}
	return (path);
}
