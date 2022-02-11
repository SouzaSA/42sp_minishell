/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:09:27 by edpaulin          #+#    #+#             */
/*   Updated: 2022/02/11 17:23:36 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static int	ft_is_dot_dir(char *dir);

void	ft_get_file_list(t_list **list, char *pattern, DIR *folder, char *path)
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
