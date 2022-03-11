/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_ast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:32:30 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/03 18:47:12 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

static void	ft_ast_cleaner(t_ast **ast);

void	ft_destroy_ast(t_ast **ast)
{
	ft_ast_cleaner(ast);
	*ast = NULL;
}

static void	ft_ast_cleaner(t_ast **ast)
{
	if (!(*ast))
		return ;
	ft_ast_cleaner(&(*ast)->first_child);
	ft_ast_cleaner(&(*ast)->next_sibling);
	ft_destroy_command(&(*ast)->blk);
	free(*ast);
	*ast = NULL;
}
