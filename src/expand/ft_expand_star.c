/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_star.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:50:25 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/13 11:08:20 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static void		ft_couple(t_list **list, t_list *prev, t_list *exp, t_list **n);
static t_list	*ft_expand(char *str);
static void		ft_expand_from_first_dir(t_list **list, t_list *split);

void	ft_expand_star(t_list **list)
{
	t_list	*node;
	t_list	*expanded;
	t_list	*prev;

	node = *list;
	prev = NULL;
	while (node)
	{
		if (node->content && strchr((char *)node->content, '*'))
		{
			expanded = ft_expand((char *)node->content);
			if (expanded)
				ft_couple(list, prev, expanded, &node);
		}
		prev = node;
		node = node->next;
	}
}

static void	ft_couple(t_list **list, t_list *prev, t_list *exp, t_list **n)
{
	t_list	*last;
	t_list	*aux;

	if (!prev)
	{
		last = ft_lstlast(exp);
		*list = exp;
		last->next = (*n)->next;
	}
	else
	{
		prev->next = exp;
		last = ft_lstlast(exp);
		last->next = (*n)->next;
	}
	aux = *n;
	*n = ft_lstlast(exp);
	ft_lstdelone(aux, &free);
}

static t_list	*ft_expand(char *str)
{
	t_list	*split;
	t_list	*list;
	t_file	*fl;

	if (!str)
		return (NULL);
	split = ft_get_splitted_path(str);
	if (!split)
		return (NULL);
	fl = (t_file *)split->content;
	list = NULL;
	if (ft_lstsize(split) > 1 && ft_strchr(fl->name, '*'))
		ft_expand_from_first_dir(&list, split);
	else if (!split->next)
		ft_add_expansion_to_list(&list, split, NULL);
	else
		ft_expand_list(&list, split, fl->name);
	ft_lstclear(&split, &ft_del_content_file_struct);
	return (list);
}

static void	ft_expand_from_first_dir(t_list **list, t_list *split)
{
	DIR				*folder;
	struct dirent	*entry;
	char			*pattern;

	folder = opendir(".");
	if (!folder)
		return ;
	entry = readdir(folder);
	pattern = ft_strdup(((t_file *)split->content)->name);
	while (entry)
	{
		if (ft_match_star(pattern, entry->d_name) \
		&& ft_is_dir(entry->d_type))
		{
			free(((t_file *)split->content)->name);
			((t_file *)split->content)->name = ft_strdup(entry->d_name);
			ft_expand_list(list, split, ((t_file *)split->content)->name);
		}
		entry = readdir(folder);
	}
	free(pattern);
	closedir(folder);
}
