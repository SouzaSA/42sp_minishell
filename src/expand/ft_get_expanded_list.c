/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_expanded_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:05:59 by edpaulin          #+#    #+#             */
/*   Updated: 2022/02/11 17:12:39 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static int		ft_is_dir(unsigned char type);
static char		*ft_pathcat(char *s1, char *s2);

void	ft_get_expanded_list(t_list **list, t_list *dir, char *dir_to_open)
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
		ft_get_file_list(list, (char *)dir->content, folder, dir_to_open);
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
				ft_get_expanded_list(list, dir->next, next_dir_to_open);
				free(next_dir_to_open);
			}
			entry = readdir(folder);
		}
	}
	closedir(folder);
}

static int	ft_is_dir(unsigned char type)
{
	return (type == 4);
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
