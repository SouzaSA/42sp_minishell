/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_node_val_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:33:16 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/03 19:03:02 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_set_node_val_str(t_ast *node, t_cmd_blk *cmd)
{
	node->type = AST_CMD;
	if (!cmd)
	{
		node->blk = NULL;
	}
	else
	{
		node->blk = cmd;
	}
}
