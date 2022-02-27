/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 12:20:09 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/26 21:07:39 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtins.h"

static void		ft_export_print(t_shell *shell);
static void 	ft_export_worker(t_shell *shell, t_list *exp_var);
static t_list	*ft_search_local(t_shell *shell, char *key);

int	ft_export(t_shell *shell, t_list *exp_var)
{
	char	*assign;
	char	*key;

	shell->error_status = 0;
	if (!ft_strcmp((char *)exp_var->content, "export"))
	{
		if (exp_var && ft_lstsize(exp_var) == 1)
			ft_export_print(shell);
		exp_var = exp_var->next;
	}
	while (exp_var)
	{
		assign = (char *)exp_var->content;
		key = ft_substr(assign, 0, (ft_strchr(assign, '=') - &assign[0]));
		if (ft_isidentifier(key))
			ft_export_worker(shell, exp_var);
		else
		{
			shell->error_status = 1;
			ft_export_error((char *)exp_var->content, FLAG_ERROR_OWN);
		}
		free(key);
		exp_var = exp_var->next;
	}
	return (0);
}

static void	ft_export_print(t_shell *shell)
{
	t_list *env_node;

	env_node = shell->env_list;
	while (env_node)
	{
		ft_putstr_fd(((t_dictionary *)env_node->content)->key, 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd("\"", 1);
		ft_putstr_fd(((t_dictionary *)env_node->content)->value, 1);
		ft_putstr_fd("\"\n", 1);
		env_node = env_node->next;
	}
}

static void ft_export_worker(t_shell *shell, t_list *exp_var)
{
	char	*assign;
	char	*key;
	t_list	*local_var;

	assign = (char *)exp_var->content;
	key = ft_substr(assign, 0, (ft_strchr(assign, '=') - &assign[0]));
	if (ft_strchr(assign, '='))
	{
		ft_export_exec(shell, exp_var);
	}
	else
	{
		local_var = ft_search_local(shell, key);
		if (local_var)
			ft_env_search_and_add(shell, local_var);
	}
	free(key);
}

static t_list	*ft_search_local(t_shell *shell, char *key)
{
	t_list	*node;
	t_list	*previous;

	node = shell->vars;
	previous = NULL;
	while (node && ft_strcmp(key, ((t_dictionary *)node->content)->key))
	{
		previous = node;
		node = node->next;
	}
	if (node)
	{
		if (!previous)
			shell->vars = node->next;
		else
			previous->next = node->next;
	}
	return (node);
}
