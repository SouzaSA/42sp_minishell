/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_symbol_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 12:29:32 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/25 15:20:47 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	*ft_stk_node(enum e_symbol symbol)
{
	t_stk_node	*stk_node;

	stk_node = (t_stk_node *)malloc(sizeof(t_stk_node));
	stk_node->tok_type = symbol;
	stk_node->ast_node = NULL;
	return ((void *)stk_node);
}
