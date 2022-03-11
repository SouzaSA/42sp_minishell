/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_after.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 11:25:58 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/26 21:32:21 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_after(t_list *node, t_list *new)
{
	t_list	*aux;

	if (node && new)
	{
		aux = node->next;
		node->next = new;
		new->next = aux;
	}
}
