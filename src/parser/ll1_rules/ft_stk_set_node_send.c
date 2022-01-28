/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_set_node_send.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:37:41 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/27 20:40:23 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_stk_set_node_send(t_stk_node **new, t_stk_node *old, int type)
{
	*new = (t_stk_node *)ft_stk_node(type);
	old->ast_node->first_child = ft_new_node(AST_TMP);
	(*new)->ast_node = old->ast_node->first_child;
}
