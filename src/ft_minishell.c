/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:36:17 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/16 10:16:20 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static int	ft_set_status(char *line);

int	ft_minishell(char **envp)
{
	//char	**path;
	char	*line;
	//char	**splitted_line;
	int 	status;

	if (!envp)//tirar
		write(1,"boo\n",4); // tirar
	status = 1;
	//path = ft_get_path(envp);
	while (status)
	{
		line = readline("$ ");
		if (!line)
		{
			write(2, "exit\n", 5);
			status = 0;
		}
		if (line && ft_strlen(line) == 0)
		{
			free(line);
			continue ;
		}
		add_history(line);
		ft_putendl_fd(line, 1);
		status = ft_set_status(line);
		free(line);
	}
	rl_clear_history();
	return (0);
}

static int	ft_set_status(char *line)
{
	int		status;

	status = 1;
	if (ft_strcmp("exit", line) == 0)
		status = 0;
	return (status);
}
