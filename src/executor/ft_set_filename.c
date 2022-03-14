/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_filename.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:31:27 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/14 10:56:03 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_set_filename(t_list **redir_node, char **filename)
{
	int		rtn;
	t_list	*new;
	void	*aux;

	rtn = 0;
	new = ft_lstnew(ft_strdup((*redir_node)->content));
	ft_expand_star(&new);
	if (ft_lstsize(new) > 1)
	{
		rtn = ft_expand_error((char *)(*redir_node)->content, FLAG_ERROR_REDIR);
		*filename = NULL;
		ft_lstclear(&new, &free);
	}
	else
	{
		aux = (*redir_node)->content;
		(*redir_node)->content = new->content;
		new->content = aux;
		*filename = ft_str_remove_quotes((char *)(*redir_node)->content);
		ft_lstdelone(new, &free);
	}
	return (rtn);
}
