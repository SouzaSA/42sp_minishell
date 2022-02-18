/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_expanded_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:05:59 by edpaulin          #+#    #+#             */
/*   Updated: 2022/02/18 11:06:36 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static void	ft_expand(t_list **list, t_list *dir, char *dir_to_open, DIR *folder);
static void	ft_next_dir(t_list **list, t_list *dir, char *dir_to_open, DIR *folder);
static int	ft_is_dir(unsigned char type);

void	ft_get_expanded_list(t_list **list, t_list *dir, char *dir_to_open)
{
	DIR				*folder;

	if (!dir)
		return ;
	folder = opendir(dir_to_open);
	if (!folder)
		return ;
	if (!dir->next)
		ft_expand(list, dir, dir_to_open, folder);
	else
		ft_next_dir(list, dir, dir_to_open, folder);
	closedir(folder);
}

static void	ft_expand(t_list **list, t_list *dir, char *dir_to_open, DIR *folder)
{
	char	*tmp;
	size_t	last_char;

	tmp = NULL;
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

static void	ft_next_dir(t_list **list, t_list *dir, char *dir_to_open, DIR *folder)
{
	struct dirent	*entry;
	char			*next_dir_to_open;

	entry = readdir(folder);
	while (entry)
	{
		if (ft_is_dir(entry->d_type) \
		&& !ft_is_dot_dir(entry->d_name) \
		&& ft_match_star((char *)dir->content, entry->d_name))
		{
			next_dir_to_open = ft_pathcat(dir_to_open, entry->d_name);
			ft_get_expanded_list(list, dir->next, next_dir_to_open);
			free(next_dir_to_open);
		}
		entry = readdir(folder);
	}
}

static int	ft_is_dir(unsigned char type)
{
	return (type == 4);
}
