/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:36:17 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/05 11:21:11 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"
#include "ft_signals.h"

#include <curses.h>
#include <term.h>

// static int	ft_set_status(char *line);

int	ft_minishell(char **envp)
{
	t_shell		shell;
	int			status;
	char		*prompt;

	ft_init_minishell(&shell, envp);
	//ft_env(&shell);
	status = 1;
	while (status)
	{
		ft_handle_prompt_signals();
		prompt = ft_get_prompt();
		shell.line = readline(prompt);
		free(prompt);
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
