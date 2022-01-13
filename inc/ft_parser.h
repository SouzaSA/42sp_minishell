/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 20:54:43 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/13 12:20:59 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include "ft_scanner.h"

enum	e_node_type
{
	NTS_START,
	NTS_AND_OR,
	NTS_PIPELINE,
	NTS_COMMAND,
	NTS_SUBSHELL,
	NTS_SIMPLE_CMD,
	NTS_PREFIX,
	NTS_SULFIX,
	NTS_REDIRECT_LIST,
	NTS_IO_REDIRECT,
	NTS_IO_FILE,
	NTS_IO_HERE,
	TS_AND_IF,
	TS_OR_IF,
	TS_PIPE,
	TS_LBRACE,
	TS_RBRACE,
	TS_WORD,
	TS_ASSIGNMENT,
	TS_LESS,
	TS_GREAT,
	TS_DGREAT,
	TS_LESSGREAT,
	TS_DLES,
};

typedef struct s_ast_node
{
	enum e_node_type	type;
	char				*str;
	int					children;
	struct s_node		*first_child;
	struct s_node		*next_sibling;
	struct s_node		*prev_sibling;
}	t_ast_node;

void	ft_add_child_node(t_ast_node *parent, t_ast_node *child);
void	ft_free_node_tree(t_ast_node *node);
t_ast_node	*ft_new_node(enum e_node_type type);
t_ast_node	*ft_parse_simple_command(t_scanner *scan, t_token *tok);
void	ft_set_node_val_str(t_ast_node *node, char *val);
#endif
