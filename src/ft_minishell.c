/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:36:17 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/16 21:15:43 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static int	ft_set_status(char *line);
static void	ft_print_dictionary(void *dic_item); //tirar só para teste

int	ft_minishell(char **envp)
{
	t_shell	shell;
	char	*line;
	int 	status;

	ft_init_minishell(&shell, envp);
	ft_lstiter(shell.env_list, &ft_print_dictionary);
	ft_destroy_vars(&shell);
	status = 1;
	while (status)
	{
		line = readline("\033[0;33m$\e[0;39m ");
		if (!line || (line && !ft_set_status(line)))
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

static void	ft_print_dictionary(void *dic_item) //tirar só para teste
{
	if (dic_item)
	{
		if (((t_dictionary *)dic_item)->key)
			ft_putstr_fd(((t_dictionary *)dic_item)->key, 1);
		write(1, " = ", 3);
		if (((t_dictionary *)dic_item)->value)
			ft_putendl_fd(((t_dictionary *)dic_item)->value, 1);
	}
}
