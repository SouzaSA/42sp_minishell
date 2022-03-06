/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:36:17 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/06 15:53:57 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"
#include "ft_signals.h"
#include <curses.h>
#include <term.h>

static void	ft_free_line(t_shell *shell);
static void	ft_no_line(void);

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
			ft_no_line();
		if (shell.line && ft_strlen(shell.line) == 0)
		{
			ft_free_line(&shell);
			continue ;
		}
		add_history(shell.line);
		ft_executor(&shell, shell.line);
		ft_free_line(&shell);
		shell.lineno++;
	}
	rl_clear_history();
	ft_destroy_shell(&shell);
	return (0);
}

static void	ft_free_line(t_shell *shell)
{
	free(shell->line);
	shell->line = NULL;
}

static void	ft_no_line(void)
{
	write(1, "\n", 1);
	exit(0);
}
