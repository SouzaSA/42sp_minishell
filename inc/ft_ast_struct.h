/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:08:23 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/15 15:11:17 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AST_STRUCT_H
# define FT_AST_STRUCT_H
# include "libft.h"

enum e_node_type
{
	AST_CMD,
	AST_PIPE,
	AST_REDIR,
	AST_AND_OR,
	AST_AND,
	AST_OR,
	AST_ASSIGN,
	AST_TMP,
};

typedef struct s_command
{
	t_list	*cmd;
	t_list	*redir;
	t_list	*assign;
}	t_command;

typedef struct s_ast
{
	enum e_node_type	type;
	t_command			*cmd;
	int					children;
	struct s_ast		*first_child;
	struct s_ast		*next_sibling;
	struct s_ast		*prev_sibling;
}	t_ast;

#endif