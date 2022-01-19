/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 20:54:43 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/19 11:12:19 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include "ft_scanner.h"

enum e_node_type
{
	AST_CMD,
	AST_LBRACE,
	AST_RBRACE,
	AST_PIPE,
	AST_AND,
	AST_OR,
};

typedef	struct	s_command
{
	t_list	*cmd;
	t_list	*redir;
	t_list	*assign;
}	t_command;

typedef struct s_ast_node
{
	enum e_node_type		type;
	t_command				*cmd;
	int						children;
	struct s_node			*first_child;
	struct s_node			*next_sibling;
	struct s_node			*prev_sibling;
}	t_ast_node;

void	ft_add_child_node(t_ast_node *parent, t_ast_node *child);
void	ft_free_node_tree(t_ast_node *node);
t_ast_node	*ft_new_node(enum e_symbol type);
t_ast_node	*ft_parse_simple_command(t_scanner *scan, t_token *tok);
void	ft_set_node_val_str(t_ast_node *node, char *val);

/*
* LL(1) RULES
*/
void	ft_start(t_list **symbol_stack, enum e_symbol tok_type);
void	ft_and_or(t_list **symbol_stack, enum e_symbol tok_type);
void	ft_and_or1(t_list **symbol_stack, enum e_symbol tok_type);
void	ft_pipeline(t_list **symbol_stack, enum e_symbol tok_type);
void	ft_pipeline1(t_list **symbol_stack, enum e_symbol tok_type);
void	ft_command(t_list **symbol_stack, enum e_symbol tok_type);
void	ft_command1(t_list **symbol_stack, enum e_symbol tok_type);
void	ft_subshell(t_list **symbol_stack, enum e_symbol tok_type);
void	ft_simple_cmd(t_list **symbol_stack, enum e_symbol tok_type);
void	ft_simple_cmd1(t_list **symbol_stack, enum e_symbol tok_type);
void	ft_simple_cmd2(t_list **symbol_stack, enum e_symbol tok_type);
void	ft_cmd_prefix(t_list **symbol_stack, enum e_symbol tok_type);
void	ft_cmd_prefix1(t_list **symbol_stack, enum e_symbol tok_type);
void	ft_cmd_sulfix(t_list **symbol_stack, enum e_symbol tok_type);
void	ft_cmd_sulfix1(t_list **symbol_stack, enum e_symbol tok_type);
void	ft_cmd_redirect_list(t_list **symbol_stack, enum e_symbol tok_type);
void	ft_cmd_redirect_list1(t_list **symbol_stack, enum e_symbol tok_type);
void	ft_io_redirect(t_list **symbol_stack, enum e_symbol tok_type);
void	ft_io_file(t_list **symbol_stack, enum e_symbol tok_type);
void	ft_io_here(t_list **symbol_stack, enum e_symbol tok_type);
void	ft_epsilon(t_list **symbol_stack, enum e_symbol tok_type);

#endif
