/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 20:54:43 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/02 16:22:55 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include <sys/types.h>
# include <sys/wait.h>
# include "ft_ast_struct.h"
# include "ft_scanner.h"
# include "ft_error.h"
# include "ft_utils.h"

typedef struct s_stk_node
{
	enum e_symbol	stk_type;
	enum e_ast_type	ast_type;
	t_ast			*ast_node;
}	t_stk_node;
/*
* Parser worker
*/
t_ast	*ft_parser(char *line, void (***tt)(t_list **, enum e_symbol));
t_ast	*ft_add_child_node(t_ast *parent, t_ast *child);
void	ft_free_node_tree(t_ast *node);
t_ast	*ft_new_node(enum e_ast_type type);
void	ft_set_node_val_str(t_ast *node, t_command *cmd);
t_ast	*ft_syntax(t_list *toks, void (***tt)(t_list **, enum e_symbol));
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
