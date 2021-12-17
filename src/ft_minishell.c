/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:36:17 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/17 11:40:15 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static int	ft_set_status(char *line);
static void	ft_print_dictionary(void *dic_item); //tirar só para teste

void	del(void *content)
{
	if (content)
	{
		free(content);
		content = NULL;
	}
}

void	echo(char *msg, int flag)
{
	if (flag == 1)
		ft_putendl_fd(msg, 1);
	else
		ft_putstr_fd(msg, 1);
}

void	env(t_shell *shell)
{
	ft_lstiter(shell->env_list, &ft_print_dictionary);
}

void	export(t_shell *shell, char *line)
{
	t_dictionary	*dic_item;
	
	dic_item = (t_dictionary *)malloc(sizeof(t_dictionary));
	dic_item->key = ft_strdup(line);
	dic_item->value = ft_strdup(line);
	ft_lstadd_back(&shell->env_list, ft_lstnew(dic_item));
}

void	unset(t_shell *shell)
{
	t_list	*node;
	t_list	*last;

	last = ft_lstlast(shell->env_list);
	node = shell->env_list;
	while (node->next->next != NULL)
		node = node->next;
	ft_lstdelone(last, &del);
	node->next = NULL;
}

int	ft_minishell(char **envp)
{
	t_shell	shell;
	char	*line;
	int 	status;

	ft_init_minishell(&shell, envp);
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
		if (ft_strcmp(line, "env") == 0)
			env(&shell);
		else if (ft_strcmp(line, "export") == 0)
			export(&shell, line);
		else if (ft_strcmp(line, "unset") == 0)
			unset(&shell);
		else if (ft_strcmp(line, "echo") == 0)
			echo("with new line", 1);
		else if (ft_strcmp(line, "echo -n") == 0)
			echo("no new line", 0);
		free(line);
	}
	ft_destroy_vars(&shell);
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
