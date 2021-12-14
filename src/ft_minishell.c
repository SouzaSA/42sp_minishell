/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:36:17 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/14 15:46:45 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_minishell(char **envp)
{
	char	**path;
	char	*line;
	char	**splitted_line;
	int 	status;

	status = 1;
	path = ft_get_path(envp);
	while (status)
	{
		printf("> ");
		line = get_next_line(0);
		splitted_line = ft_split(line, ' ');
		status = ft_execute(splitted_line, path, envp);

		free(line);
		ft_split_destroy(splitted_line);
	}
	return (0);
}
