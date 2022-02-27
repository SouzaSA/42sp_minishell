/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 09:17:31 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/27 10:52:59 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtins.h"

static void		ft_exchange_node(t_shell *shell, t_list *old, t_list *new);
static t_list	*ft_search_right_pos(t_list *list, t_list *new_node);

int	ft_export_exec(t_shell *shell, t_list *exp_var)
{
	int				rtn;
	long			idx;
	char			*assign;
	t_dictionary	*dic_item;
	t_list			*new_node;

	rtn = 0;
	dic_item = (t_dictionary *)malloc(sizeof(t_dictionary));
	if (!dic_item)
	{
		shell->error_status = 1;
		return (1);
	}
	assign = (char *)exp_var->content;
	idx = (long)(ft_strchr(assign, '=') - &assign[0]);
	dic_item->key = ft_substr(assign, 0, idx);
	dic_item->value = ft_substr(assign, idx + 1, ft_strlen(assign));
	new_node = ft_lstnew(dic_item);
	if (new_node)
		ft_env_search_and_add(shell, new_node);
	return (rtn);
}

void	ft_env_search_and_add(t_shell *shell, t_list *new_node)
{
	char	*new_node_key;
	char	*dic_key;
	t_list	*element;

	if (shell->env_list)
	{
		dic_key = NULL;
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
	while (list && ft_strcmp(dic_key, new_node_key) <= 0)
	{
		element = list;
		list = list->next;
		if (list)
			dic_key = ((t_dictionary *)list->content)->key;
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
