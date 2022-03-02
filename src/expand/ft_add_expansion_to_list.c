/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_expansion_to_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:19:23 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/02 18:29:12 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static int	ft_check_file(enum e_type target_type, int file_type);

void	ft_add_expansion_to_list(t_list **list, t_list *dir, char *dir_to_open)
{
	struct dirent	*entry;
	DIR				*folder;
	char			*concat;
	t_list			*new;
	t_file			*fl;

	if (!dir_to_open)
		folder = opendir(".");
	else
		folder = opendir(dir_to_open);
	if (!folder)
		return ;
	entry = readdir(folder);
	while (entry)
	{
		fl = (t_file *)dir->content;
		if (ft_check_file(fl->type, entry->d_type) \
			&& ft_match_star(fl->name, entry->d_name))
			{
				if (!dir_to_open)
					concat = ft_strdup(entry->d_name);
				else
					concat = ft_pathcat(dir_to_open, entry->d_name);
				new = ft_lstnew(concat);
				if (!new)
				{
					free(concat);
					ft_lstclear(list, ft_del_content);
					return ;
				}
				ft_lstadd_back(list, new);
			}
		entry = readdir(folder);
	}
	closedir(folder);
}

static int	ft_check_file(enum e_type target_type, int file_type)
{
	if (target_type == T_DIR)
		return (ft_is_dir(file_type));
	return (1);
}
