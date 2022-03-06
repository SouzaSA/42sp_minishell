/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_star.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:50:25 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/06 20:14:06 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static void		ft_expand_cmd_star(t_list **list);
static void		ft_couple(t_list **list, t_list *prev, t_list *exp, t_list **n);
static void		ft_expand_redir_star(t_list **list);
static t_list	*ft_expand(char *str);

void	ft_expand_star(t_list *ast_stk)
{
	t_list		*node;
	t_cmd_blk	*blk;

	node = ast_stk;
	while (node)
	{
		if (node->content && ((t_ast *)node->content)->blk)
		{
			blk = ((t_ast *)node->content)->blk;
			ft_expand_cmd_star(&blk->cmd);
			ft_expand_redir_star(&blk->redir);
		}
		node = node->next;
	}
}

static void	ft_expand_cmd_star(t_list **list)
{
	t_list	*node;
	t_list	*expanded;
	t_list	*prev;

	node = *list;
	prev = NULL;
	while (node)
	{
		if (strchr((char *)node->content, '*'))
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

static void	ft_expand_redir_star(t_list **list)
{
	t_list	*node;
	t_list	*expanded;

	node = *list;
	while (node)
	{
		if (ft_strchr((char *)node->content, '*'))
		{
			expanded = ft_expand((char *)node->content);
			if (expanded && ft_lstsize(expanded) == 1)
			{
				free(node->content);
				node->content = ft_strdup((char *)expanded->content);
			}
			if (expanded)
				ft_lstclear(&expanded, &free);
		}
		node = node->next;
	}
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
	if (!split->next)
		ft_add_expansion_to_list(&list, split, NULL);
	else
		ft_expand_list(&list, split, fl->name);
	ft_lstclear(&split, &ft_del_content_file_struct);
	return (list);
}
