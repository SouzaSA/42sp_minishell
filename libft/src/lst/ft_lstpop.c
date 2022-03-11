/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 10:12:26 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/15 18:48:32 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstpop(t_list **lst)
{
	t_list	*node;
	void	*content;

	content = NULL;
	if (lst && *lst)
	{
		node = (*lst)->next;
		content = (*lst)->content;
		free(*lst);
		*lst = node;
	}
	return (content);
}
