/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_star.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:50:25 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/02 18:54:47 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

t_list	*ft_expand_star(char *str)
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