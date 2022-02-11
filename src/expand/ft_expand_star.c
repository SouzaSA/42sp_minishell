/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_star.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:36:40 by edpaulin          #+#    #+#             */
/*   Updated: 2022/02/11 14:50:01 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static t_list	*ft_split_path(char *path);
static int		ft_add_split_to_list(t_list **list, char *split);
static void		ft_print_list(t_list *list);
static int		ft_is_dir(unsigned char type);
static void		ft_get_expanded_values(t_list **list, t_list *dir, char *dir_to_open);
static char		*ft_pathcat(char *s1, char *s2);
static void		ft_get_filename_list(t_list **list, char *pattern, DIR *folder, char *path);
static int		ft_is_dot_dir(char *dir);

t_list	*ft_expand_star(char *str)
{
	t_list	*expanded_values;
	t_list	*splitted_path;

	expanded_values = NULL;
	splitted_path = ft_split_path(str);
	ft_get_expanded_values(&expanded_values, splitted_path->next, (char *)splitted_path->content);
	// ft_print_list(splitted_path);
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

static int	ft_is_dir(unsigned char type)
{
	return (type == 4);
}


static void	ft_get_expanded_values(t_list **list, t_list *dir, char *dir_to_open)
{
	DIR				*folder;
	struct dirent	*entry;
	char			*next_dir_to_open;
	char			*tmp;
	size_t			last_char;
	
	tmp = NULL;
	if (!dir)
		return ;
	folder = opendir(dir_to_open);
	if (!dir->next)
	{
		last_char = ft_strlen(dir_to_open) - 1;
		if (dir_to_open[last_char] != '/')
		{
			tmp = dir_to_open;
			dir_to_open = ft_strjoin(tmp, "/");
		}
		ft_get_filename_list(list, (char *)dir->content, folder, dir_to_open);
		if (tmp)
			free(dir_to_open);
	}
	else
	{
		entry = readdir(folder);
		while (entry)
		{
			if (ft_is_dir(entry->d_type) && ft_match_star((char *)dir->content, entry->d_name))
			{
				next_dir_to_open = ft_pathcat(dir_to_open, entry->d_name);
				ft_get_expanded_values(list, dir->next, next_dir_to_open);
				free(next_dir_to_open);
			}
			entry = readdir(folder);
		}
	}
	closedir(folder);
}

static char	*ft_pathcat(char *s1, char *s2)
{
	size_t	last_char;
	char	*path_concatenated;
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	last_char = ft_strlen(s1) - 1;
	if (s1[last_char] == '/')
	{
		path_concatenated = ft_strjoin(s1, s2);
		if (!path_concatenated)
			return (NULL);
	}
	else
	{
		tmp = ft_strjoin(s1, "/");
		if (!tmp)
			return (NULL);
		path_concatenated = ft_strjoin(tmp, s2);
		free(tmp);
		if (!path_concatenated)
			return (NULL);
	}
	return (path_concatenated);
}

static void	ft_get_filename_list(t_list **list, char *pattern, DIR *folder, char *path)
{
	t_list			*new;
	struct dirent	*entry;
	char			*complete_path;

	if (!pattern || !folder)
		return ;
	entry = readdir(folder);
	while (entry)
	{
		if (ft_match_star(pattern, entry->d_name) && !ft_is_dot_dir(entry->d_name))
		{
			complete_path = ft_strjoin(path, entry->d_name);
			if (!complete_path)
				return ;
			new = ft_lstnew(complete_path);
			if (!new)
			{
				free(complete_path);
				ft_lstclear(list, &ft_del_list_content);
				return ;
			}
			ft_lstadd_back(list, new);
		}
		entry = readdir(folder);
	}
}

static int	ft_is_dot_dir(char *dir)
{
	return (!ft_strcmp(dir, ".") || !ft_strcmp(dir, ".."));
}
