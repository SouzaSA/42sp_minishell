/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:36:17 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/03 20:03:09 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

#include <curses.h>
#include <term.h>

// static int	ft_set_status(char *line);
static void	ft_print_dir(void);

int	ft_minishell(char **envp)
{
	t_shell		shell;
	int			status;

	ft_init_minishell(&shell, envp);
	//ft_env(&shell);
	status = 1;
	while (status)
	{
		ft_print_dir();
		shell.line = readline("\033[0;33m$\e[0;39m ");
		if (!shell.line)
		{
			write(1, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		if (shell.line && ft_strlen(shell.line) == 0)
		{
			free(shell.line);
			shell.line = NULL;
			continue ;
		}
		add_history(shell.line);
		ft_executor(&shell, shell.line);
		free(shell.line);
		shell.line = NULL;
	}
	rl_clear_history();
	ft_destroy_shell(&shell);
	return (0);
}

// static int	ft_set_status(char *line)
// {
// 	int		status;

// 	status = 1;
// 	if (ft_strcmp("exit", line) == 0)
// 		status = 0;
// 	return (status);
// }

static void	ft_print_dir(void)
{
	char	cwd[1024];

	getcwd(cwd, sizeof(cwd));
	printf("\033[0;32m%s\e[0;39m", cwd);
}
