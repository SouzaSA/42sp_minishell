/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:36:17 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/05 15:48:28 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"
#include "ft_signals.h"
#include <curses.h>
#include <term.h>

int	ft_minishell(char **envp)
{
	t_shell		shell;
	char		*prompt;

	ft_init_minishell(&shell, envp);
	while (1)
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
