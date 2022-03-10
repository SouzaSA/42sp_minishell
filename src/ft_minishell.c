/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:36:17 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/10 16:50:36 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"
#include "ft_signals.h"
#include <curses.h>
#include <term.h>

static void	ft_no_line(t_shell *shell);
static int	ft_lineck(char *line);
static void	ft_free_line(t_shell *shell);

int	ft_minishell(char **envp)
{
	char		*prompt;
	t_shell		shell;

	ft_init_minishell(&shell, envp);
	while (1)
	{
		ft_handle_prompt_signals();
		prompt = ft_get_prompt();
		shell.line = readline(prompt);
		free(prompt);
		if (!shell.line)
			ft_no_line(&shell);
		if (shell.line && (ft_strlen(shell.line) == 0 || ft_lineck(shell.line)))
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

static void	ft_no_line(t_shell *shell)
{
	rl_clear_history();
	ft_destroy_shell(shell);
	write(1, "\n", 1);
	exit(0);
}

static int	ft_lineck(char *line)
{
	int		has_any;
	char	*trimmed;

	trimmed = ft_strtrim(line, " ");
	has_any = 0;
	if (!trimmed || ft_strlen(trimmed) == 0)
		has_any = 1;
	free(trimmed);
	return (has_any);
}

static void	ft_free_line(t_shell *shell)
{
	free(shell->line);
	shell->line = NULL;
}
