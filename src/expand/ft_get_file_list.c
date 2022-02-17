/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:09:27 by edpaulin          #+#    #+#             */
/*   Updated: 2022/02/16 17:04:36 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static int	ft_add_file(t_list **list, char *path, char *file);

void	ft_get_file_list(t_list **list, char *pattern, DIR *folder, char *path)
{
	struct dirent	*entry;
	char			*file;

	if (!pattern || !folder)
		return ;
	entry = readdir(folder);
	while (entry)
	{
		file = entry->d_name;
		if (ft_match_star(pattern, file) && !ft_is_dot_dir(file))
		{
			if (ft_add_file(list, path, entry->d_name))
			{
				ft_lstclear(list, &ft_del_list_content);
				return ;
			}
		}
		entry = readdir(folder);
	}
}

static int	ft_add_file(t_list **list, char *path, char *file)
{
	char	*complete_path;
	t_list	*new;

	complete_path = ft_strjoin(path, file);
	if (!complete_path)
		return (1);
	new = ft_lstnew(complete_path);
	if (!new)
	{
		free(complete_path);
		return (2);
	}
	ft_lstadd_back(list, new);
	return (0);
}
