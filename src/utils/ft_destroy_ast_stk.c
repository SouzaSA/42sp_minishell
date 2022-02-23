/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_ast_stk.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:35:25 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/22 14:42:12 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_destroy_ast_stk(t_list **ast_stk)
{
	t_ast	*ast;
	t_list	*node;

	if (ast_stk && *ast_stk)
	{
		node = *ast_stk;
		while (ft_lstsize(node))
		{
			ast = (t_ast *)ft_lstpop(&node);
			if (ast->cmd)
				ft_destroy_command(&ast->cmd);
			free(ast);
		}
		*ast_stk = NULL;
	}
}
