/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 12:20:09 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/22 19:45:30 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void		ft_env_add_size1(t_shell *shell, t_list *new_node);
static void		ft_search_and_add(t_shell *shell, t_list *new_node);
static t_list	*ft_search_right_pos(t_list *list, t_list *new_node);
static void		ft_exchange_node(t_shell *shell, t_list *old, t_list *new);

void	ft_export(t_shell *shell, char *key, char *value)
{
	t_dictionary	*dic_item;
	t_list			*new_node;
	t_list			*list;

	if (shell && key)
	{
		dic_item = (t_dictionary *)malloc(sizeof(t_dictionary));
		dic_item->key = key;
		dic_item->value = value;
		new_node = ft_lstnew(dic_item);
		list = shell->env_list;
		if (!list && new_node)
			ft_lstadd_front(&shell->env_list, new_node);
		else if (ft_lstsize(list) == 1)
			ft_env_add_size1(shell, new_node);
		else
			ft_search_and_add(shell, new_node);
	}
}

static void	ft_env_add_size1(t_shell *shell, t_list *new_node)
{
	char	*new_node_key;
	char	*dic_key;

	if (shell)
	{
		if (shell->env_list && new_node)
		{
			dic_key = ((t_dictionary *)shell->env_list->content)->key;
			new_node_key = ((t_dictionary *)new_node->content)->key;
			if (ft_strcmp(dic_key, new_node_key) == 0)
				ft_exchange_node(shell, shell->env_list, new_node);
			else if (ft_strcmp(dic_key, new_node_key) < 0)
				ft_lstadd_back(&shell->env_list, new_node);
			else
				ft_lstadd_front(&shell->env_list, new_node);
		}
	}
}

static void	ft_search_and_add(t_shell *shell, t_list *new_node)
{
	char	*new_node_key;
	char	*dic_key;
	t_list	*element;

	if (shell)
	{
		if (shell->env_list && new_node)
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
	}
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
