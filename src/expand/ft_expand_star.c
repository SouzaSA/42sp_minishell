/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_star.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:36:40 by edpaulin          #+#    #+#             */
/*   Updated: 2022/02/11 17:21:40 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static t_list	*ft_split_path(char *path);
static int		ft_add_split_to_list(t_list **list, char *split);
static void		ft_print_list(t_list *list);

t_list	*ft_expand_star(char *str)
{
	t_list	*expanded_values;
	t_list	*splitted_path;

	expanded_values = NULL;
	splitted_path = ft_split_path(str);
	ft_get_expanded_list(&expanded_values, \
						splitted_path->next, \
						(char *)splitted_path->content);
	ft_print_list(splitted_path);
	ft_print_list(expanded_values);
	return (splitted_path);
}

static t_list	*ft_split_path(char *path)
{
	char	**splitted_path;
	t_list	*split_list;
	int		i;

	split_list = NULL;
	if (path[0] == '/')
	{
		if (!ft_add_split_to_list(&split_list, "/"))
			return (NULL);
	}
	splitted_path = ft_split(path, '/');
	if (!splitted_path)
	{
		ft_lstclear(&split_list, &ft_del_list_content);
		return (NULL);
	}
	i = 0;
	while (splitted_path[i])
	{
		if (!ft_add_split_to_list(&split_list, splitted_path[i]))
		{
			ft_lstclear(&split_list, &ft_del_list_content);
			ft_split_destroy(splitted_path);
			return (NULL);
		}
		i++;
	}
	ft_split_destroy(splitted_path);
	return (split_list);
}

static int	ft_add_split_to_list(t_list **list, char *split)
{
	t_list	*new;
	char	*split_copy;

	if (!list || !split)
		return (0);
	split_copy = ft_strdup(split);
	if (!split_copy)
		return (0);
	new = ft_lstnew((void *)split_copy);
	if (!new)
	{
		free(split_copy);
		return (0);
	}
	ft_lstadd_back(list, new);
	return (1);
}

static void	ft_print_list(t_list *list)
{
	t_list	*aux;

	if (!list)
		return ;
	aux = list;
	while (aux)
	{
		ft_putendl_fd((char *)aux->content, 1);
		aux = aux->next;
	}
}
