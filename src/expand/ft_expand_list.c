/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:30:45 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/04 18:00:05 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static void	ft_loop_to_expand(DIR *folder, t_list **list, t_list *dir, char *p);
static char	*ft_get_file_name(t_list *list);

void	ft_expand_list(t_list **list, t_list *dir, char *dir_to_open)
{
	DIR	*folder;

	if (!dir->next->next)
	{
		ft_add_expansion_to_list(list, dir->next, dir_to_open);
		return ;
	}
	folder = opendir(dir_to_open);
	if (!folder)
		return ;
	ft_loop_to_expand(folder, list, dir, dir_to_open);
	closedir(folder);
}

static void	ft_loop_to_expand(DIR *folder, t_list **list, t_list *dir, char *p)
{
	struct dirent	*entry;
	char			*next_dir_to_open;

	entry = readdir(folder);
	while (entry)
	{
		if (ft_match_star(ft_get_file_name(dir->next), entry->d_name) \
		&& ft_is_dir(entry->d_type))
		{
			next_dir_to_open = ft_pathcat(p, entry->d_name);
			if (next_dir_to_open)
			{
				ft_expand_list(list, dir->next, next_dir_to_open);
				free(next_dir_to_open);
			}
		}
		entry = readdir(folder);
	}
}

static char	*ft_get_file_name(t_list *list)
{
	t_file	*fl;

	fl = (t_file *)list->content;
	return (fl->name);
}
