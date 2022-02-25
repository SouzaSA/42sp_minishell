/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 12:20:09 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/24 21:15:59 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void		ft_export_print(t_shell *shell);
static void		ft_search_and_add(t_shell *shell, t_list *new_node);
static t_list	*ft_search_right_pos(t_list *list, t_list *new_node);
static void		ft_exchange_node(t_shell *shell, t_list *old, t_list *new);

int	ft_export(t_shell *shell, t_list *exp_var)
{
	long			idx;
	char			*assign;
	t_dictionary	*dic_item;
	t_list			*new_node;

	shell->error_status = 0;
	if (!ft_strcmp((char *)exp_var->content, "export"))
	{
		if (exp_var && ft_lstsize(exp_var) == 1)
			ft_export_print(shell);
		exp_var = exp_var->next;
	}
	while (exp_var)
	{
		dic_item = (t_dictionary *)malloc(sizeof(t_dictionary));
		if (!dic_item)
			return (1);
		assign = (char *)exp_var->content;
		idx = (long)(ft_strchr(assign, '=') - &assign[0]);
		dic_item->key = ft_substr(assign, 0, idx);
		dic_item->value = ft_substr(assign, idx + 1, ft_strlen(assign));
		new_node = ft_lstnew(dic_item);
		if (new_node)
			ft_search_and_add(shell, new_node);
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

static void	ft_search_and_add(t_shell *shell, t_list *new_node)
{
	char	*new_node_key;
	char	*dic_key;
	t_list	*element;

	if (shell->env_list)
	{
		element = ft_search_right_pos(shell->env_list, new_node);
		if (element)
			dic_key = ((t_dictionary *)element->content)->key;
		new_node_key = ((t_dictionary *)new_node->content)->key;
		if (!element)
			ft_lstadd_front(&shell->env_list, new_node);
		else if (ft_strcmp(dic_key, new_node_key) == 0)
			ft_exchange_node(shell, element, new_node);
		else
			ft_lstadd_after(element, new_node);
	}
	else
		ft_lstadd_front(&shell->env_list, new_node);
}

static t_list	*ft_search_right_pos(t_list *list, t_list *new_node)
{
	t_list	*element;
	char	*new_node_key;
	char	*dic_key;

	element = NULL;
	dic_key = ((t_dictionary *)list->content)->key;
	new_node_key = ((t_dictionary *)new_node->content)->key;
	while (list && ft_strcmp(dic_key, new_node_key) < 0)
	{
		element = list;
		list = list->next;
		if (list)
		{
			dic_key = ((t_dictionary *)list->content)->key;
			new_node_key = ((t_dictionary *)new_node->content)->key;
		}
	}
	return (element);
}

static void	ft_exchange_node(t_shell *shell, t_list *old, t_list *new)
{
	t_list	*tmp_node;
	t_list	*prev_node;

	tmp_node = shell->env_list;
	prev_node = NULL;
	while (tmp_node && tmp_node != old)
	{
		prev_node = tmp_node;
		tmp_node = tmp_node->next;
	}
	if (!prev_node)
	{
		new->next = shell->env_list;
		shell->env_list = new;
	}
	else
	{
		new->next = old->next;
		prev_node->next = new;
	}
	ft_lstdelone(old, &ft_destroy_dictionary_element);
}
