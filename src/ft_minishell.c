/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:36:17 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/30 16:47:35 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_minishell(char **envp)
{
	char	**path;
	char	*line;
	char	**splited_line;
	int 	status;

	status = 1;
	path = ft_get_path(envp);
	while (status)
	{
		printf("> ");
		line = get_next_line(0);
		splited_line = ft_split(line, ' ');
		status = ft_execute(splited_line, path, envp);

		free(line);
		ft_split_destroy(splited_line);
	}
	return (0);
}
