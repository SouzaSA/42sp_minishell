/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 20:54:43 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/24 21:02:26 by sde-alva         ###   ########.fr       */
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
	struct s_ast_node	*first_child;
	struct s_ast_node	*next_sibling;
	struct s_ast_node	*prev_sibling;
}	t_ast;

/*
* Parser worker
*/
int		*ft_parser(char *line, void	(***tt)(t_list **, enum e_symbol));
void	ft_add_child_node(t_ast *parent, t_ast *child);
void	ft_free_node_tree(t_ast *node);
t_ast	*ft_new_node(enum e_symbol type);
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
enum e_symbol	*ft_new_symbol(enum e_symbol symbol);
/*
* Transition table creation and initialization
*/
void		ft_fill_transition_table(void (***tt)(t_list **, enum e_symbol));
void		ft_init_tt_start_and_or(void (***tt)(t_list **, enum e_symbol));
void		ft_init_tt_pipeline_subshell(void (***tt)(t_list **, enum e_symbol));
void		ft_init_tt_command_io_file_here(void (***tt)(t_list **, enum e_symbol));
void		ft_init_tt_simple_cmd(void (***tt)(t_list **, enum e_symbol));
void		ft_init_tt_prefix_redirect(void (***tt)(t_list **, enum e_symbol));
void		ft_init_tt_sulfix(void (***tt)(t_list **, enum e_symbol));
void		ft_init_tt_redir_list(void (***tt)(t_list **, enum e_symbol));

#endif
