/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_set_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:37:49 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/27 20:44:35 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_stk_set_node(t_stk_node **new, t_stk_node *old, int type)
{
	*new = (t_stk_node *)ft_stk_node(type);
	(*new)->ast_node = old->ast_node;
}
