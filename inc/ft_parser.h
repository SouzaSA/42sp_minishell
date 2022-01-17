/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 20:54:43 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/16 18:48:47 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include "ft_scanner.h"

enum	e_symbol
{
	NTS_START,
	NTS_AND_OR,
	NTS_AND_OR1,
	NTS_PIPELINE,
	NTS_PIPELINE1,
	NTS_COMMAND,
	NTS_COMMAND1,
	NTS_SUBSHELL,
	NTS_SIMPLE_CMD,
	NTS_SIMPLE_CMD1,
	NTS_SIMPLE_CMD2,
	NTS_PREFIX,
	NTS_PREFIX1,
	NTS_SULFIX,
	NTS_SULFIX1,
	NTS_REDIRECT_LIST,
	NTS_REDIRECT_LIST1,
	NTS_IO_REDIRECT,
	NTS_IO_FILE,
	NTS_IO_HERE,
};

typedef struct s_ast_node
{
	enum e_symbol	type;
	char				*str;
	int					children;
	struct s_node		*first_child;
	struct s_node		*next_sibling;
	struct s_node		*prev_sibling;
}	t_ast_node;

void	ft_add_child_node(t_ast_node *parent, t_ast_node *child);
void	ft_free_node_tree(t_ast_node *node);
t_ast_node	*ft_new_node(enum e_symbol type);
t_ast_node	*ft_parse_simple_command(t_scanner *scan, t_token *tok);
void	ft_set_node_val_str(t_ast_node *node, char *val);

/*
* LL(1) RULES
*/
void	ft_start(t_list **symbol_stack, enum e_tok_type tok_type);
void	ft_and_or(t_list **symbol_stack, enum e_tok_type tok_type);
void	ft_and_or1(t_list **symbol_stack, enum e_tok_type tok_type);
void	ft_pipeline(t_list **symbol_stack, enum e_tok_type tok_type);
void	ft_pipeline1(t_list **symbol_stack, enum e_tok_type tok_type);
void	ft_command(t_list **symbol_stack, enum e_tok_type tok_type);
void	ft_command1(t_list **symbol_stack, enum e_tok_type tok_type);
void	ft_subshell(t_list **symbol_stack, enum e_tok_type tok_type);
void	ft_simple_cmd(t_list **symbol_stack, enum e_tok_type tok_type);
void	ft_simple_cmd1(t_list **symbol_stack, enum e_tok_type tok_type);
void	ft_simple_cmd2(t_list **symbol_stack, enum e_tok_type tok_type);
void	ft_cmd_prefix(t_list **symbol_stack, enum e_tok_type tok_type);
void	ft_cmd_prefix1(t_list **symbol_stack, enum e_tok_type tok_type);
void	ft_cmd_sulfix(t_list **symbol_stack, enum e_tok_type tok_type);
void	ft_cmd_sulfix1(t_list **symbol_stack, enum e_tok_type tok_type);
void	ft_cmd_redirect_list(t_list **symbol_stack, enum e_tok_type tok_type);
void	ft_cmd_redirect_list1(t_list **symbol_stack, enum e_tok_type tok_type);
void	ft_io_redirect(t_list **symbol_stack, enum e_tok_type tok_type);
void	ft_io_file(t_list **symbol_stack, enum e_tok_type tok_type);
void	ft_io_here(t_list **symbol_stack, enum e_tok_type tok_type);
void	ft_epsilon(t_list **symbol_stack, enum e_tok_type tok_type);

#endif
