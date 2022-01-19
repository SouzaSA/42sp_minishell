/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:36:17 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/19 20:48:41 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

#include <curses.h>
#include <term.h>

static int	ft_set_status(char *line);

int	ft_minishell(char **envp)
{
	t_shell		shell;
	char		*line;
	int			status;


	ft_init_minishell(&shell, envp);
	ft_env(&shell);
	ft_destroy_vars(&shell);
	status = 1;
	while (status)
	{
		line = readline("\033[0;33m$\e[0;39m ");
		if (!line)
		{
			write(1, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		if (line && !ft_set_status(line))
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
		ft_parser(line, shell.transition_table);
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
