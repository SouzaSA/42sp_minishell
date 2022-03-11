/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 12:29:32 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/03 16:51:11 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	*ft_stk_node(enum e_symbol stk_type)
{
	t_stk_node	*stk_node;

	stk_node = (t_stk_node *)malloc(sizeof(t_stk_node));
	stk_node->stk_type = stk_type;
	stk_node->ast_type = AST_TMP;
	stk_node->ast_node = NULL;
	return ((void *)stk_node);
}
