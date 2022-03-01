/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_star.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:36:40 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/01 10:29:13 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

t_list	*ft_expand_star(char *str)
{
	t_list	*expanded;
	t_list	*path;

	expanded = NULL;
	path = ft_split_path(str);
	if (!path->next)
		ft_get_expanded_list(&expanded, path, ".");
	else
		ft_get_expanded_list(&expanded, path->next, (char *)path->content);
	return (expanded);
}
