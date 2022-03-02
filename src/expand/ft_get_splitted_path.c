/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_splitted_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:53:28 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/02 18:43:28 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static int		ft_add_root_dir(t_list **list);
static int		ft_fill_split_list(t_list **list, char **split);
static t_file	*ft_create_file_struct(char *file, enum e_type type);
static 	void	ft_change_last_type_to_file(t_list *list);

t_list	*ft_get_splitted_path(char *path)
{
	t_list	*list;
	char	**split;

	list = NULL;
	if (path[0] == '/')
	{
		if (ft_add_root_dir(&list))
			return (NULL);
	}
	split = ft_split(path, '/');
	if (!split)
	{
		ft_lstclear(&list, &ft_del_content);
		return (NULL);
	}
	if (ft_fill_split_list(&list, split))
	{
		ft_split_destroy(split);
		ft_lstclear(&list, &ft_del_content);
		return (NULL);
	}
	ft_split_destroy(split);
	if (path[ft_strlen(path) - 1] != '/')
		ft_change_last_type_to_file(list);
	return (list);
}

static int	ft_add_root_dir(t_list **list)
{
	t_file	*fl;
	t_list	*new;

	fl = ft_create_file_struct("/", T_DIR);
	if (!fl)
		return (1);
	new = ft_lstnew(fl);
	if (!new)
	{
		ft_clean_file_struct(fl);
		return (2);
	}
	ft_lstadd_back(list, new);
	return (0);
}

static int	ft_fill_split_list(t_list **list, char **split)
{
	t_list	*new;
	t_file	*fl;
	int		i;

	i = 0;
	while (split[i])
	{
		fl = ft_create_file_struct(split[i], T_DIR);
		if (!fl)
			return (1);
		new = ft_lstnew(fl);
		if (!new)
		{
			ft_clean_file_struct(fl);
			return (2);
		}
		ft_lstadd_back(list, new);
		i++;
	}
	return (0);
}

static t_file	*ft_create_file_struct(char *file, enum e_type type)
{
	t_file	*new;

	new = malloc(sizeof(t_file));
	if (!new)
		return (NULL);
	new->name = ft_strdup(file);
	if (!new->name)
	{
		free(new);
		return (NULL);
	}
	new->type = type;
	return (new);
}

static void	ft_change_last_type_to_file(t_list *list)
{
	t_list	*list_last;
	t_file	*fl;

	list_last = ft_lstlast(list);
	fl = (t_file *)list_last->content;
	fl->type = T_FILE;
}