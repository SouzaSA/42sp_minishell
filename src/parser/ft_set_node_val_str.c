/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_node_val_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:33:16 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/20 09:41:30 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_set_node_val_str(t_ast_node *node, t_command *cmd)
{
	node->type = AST_CMD;
	if (!cmd)
	{
		node->cmd = NULL;
	}
	else
	{
		node->cmd = cmd;
	}
}
