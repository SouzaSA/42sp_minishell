/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:45:51 by edpaulin          #+#    #+#             */
/*   Updated: 2022/02/16 19:14:06 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static int		ft_add_split_to_list(t_list **list, char *split);

t_list	*ft_split_path(char *path)
{
	t_list	*split_list;
	char	**split_arr;
	int		i;

	split_list = NULL;
	split_arr = ft_split(path, '/');
	if (!split_arr)
		return (NULL);
	if (path[0] == '/')
	{
		if (!ft_add_split_to_list(&split_list, "/"))
			return (NULL);
	}
	i = -1;
	while (split_arr[++i])
	{
		if (!ft_add_split_to_list(&split_list, split_arr[i]))
		{
			ft_lstclear(&split_list, &ft_del_list_content);
			ft_split_destroy(split_arr);
			return (NULL);
		}
	}
	ft_split_destroy(split_arr);
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
