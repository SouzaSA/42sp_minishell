/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:08:23 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/13 13:02:42 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AST_STRUCT_H
# define FT_AST_STRUCT_H
# include "libft.h"

enum e_ast_type
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

typedef struct s_cmd_blk
{
	t_list	*cmd;
	t_list	*redir;
	t_list	*assign;
}	t_cmd_blk;

typedef struct s_ast
{
	int				level;
	enum e_ast_type	type;
	t_cmd_blk		*blk;
	int				children;
	struct s_ast	*first_child;
	struct s_ast	*next_sibling;
	struct s_ast	*prev_sibling;
}	t_ast;

#endif