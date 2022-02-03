/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 20:54:43 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/03 17:54:26 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include "ft_scanner.h"

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

union u_node_val
{
	char	mono_symbol;
	char	double_symbol;
	char	**simple_command;
	char	**assignment;
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

typedef struct s_stk_node
{
	enum e_symbol		stk_type;
	enum e_node_type	ast_type;
	t_ast				*ast_node;
}	t_stk_node;
/*
* Parser worker
*/
t_ast	*ft_parser(char *line, void	(***tt)(t_list **, enum e_symbol));
t_ast	*ft_add_child_node(t_ast *parent, t_ast *child);
void	ft_free_node_tree(t_ast *node);
t_ast	*ft_new_node(enum e_node_type type);
void	ft_set_node_val_str(t_ast *node, t_command *cmd);
/*
*  LL(1) RULES
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
void	ft_cmd_redir_list(t_list **symbol_stack, enum e_symbol tok_type);
void	ft_cmd_redir_list1(t_list **symbol_stack, enum e_symbol tok_type);
void	ft_io_redirect(t_list **symbol_stack, enum e_symbol tok_type);
void	ft_io_file(t_list **symbol_stack, enum e_symbol tok_type);
void	ft_io_here(t_list **symbol_stack, enum e_symbol tok_type);
void	ft_epsilon(t_list **symbol_stack, enum e_symbol tok_type);
void	*ft_stk_node(enum e_symbol stk_type);
void	*ft_stk_add_child(t_stk_node **new, t_stk_node *old, int stk_type);
void	ft_stk_set_node(t_stk_node **new, t_stk_node *old, int type);
/*
*  Transition table creation and initialization
*/
void	ft_fill_transition_table(void (***tt)(t_list **, enum e_symbol));
void	ft_init_tt_start_and_or(void (***tt)(t_list **, enum e_symbol));
void	ft_init_tt_pipeline_subshell(void (***tt)(t_list **, enum e_symbol));
void	ft_init_tt_command_io_file_here(void (***tt)(t_list **, enum e_symbol));
void	ft_init_tt_simple_cmd(void (***tt)(t_list **, enum e_symbol));
void	ft_init_tt_prefix_redirect(void (***tt)(t_list **, enum e_symbol));
void	ft_init_tt_sulfix(void (***tt)(t_list **, enum e_symbol));
void	ft_init_tt_redir_list(void (***tt)(t_list **, enum e_symbol));

#endif
