/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:18:16 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/25 12:18:30 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static int	*ft_syntax(t_list *toks, void (***tt)(t_list **, enum e_symbol));
static void	ft_set_source(t_source *src, char *line);

int	*ft_parser(char *line, void	(***tt)(t_list **, enum e_symbol))
{
	t_ast		*ast;
	t_list		*tokens;
	t_source	src;

	ast = NULL;
	ft_set_source(&src, line);
	tokens = ft_lexer(&src);
	if (ft_syntax(tokens, tt))
		ft_semantic();
	return (ast);
}

static int	*ft_syntax(t_list *toks, void (***tt)(t_list **, enum e_symbol))
{
	t_syntax		*syntax_vars;
	void			(*production)(t_list **, enum e_symbol);
	enum e_symbol	*symbol;
	int				is_valid;

	syntax_vars->symbol_stack = NULL;
	ft_lstpush(&syntax_vars->symbol_stack, ft_new_symbol(TS_EOF));
	ft_lstpush(&syntax_vars->symbol_stack, ft_new_symbol(NTS_START));
	is_valid = 1;
	while (is_valid && ft_lstsize(syntax_vars->symbol_stack) > 0)
	{
		symbol = (enum e_symbol *)ft_lsttop(syntax_vars->symbol_stack);
		if (((t_token *)toks->content)->tok_type == *symbol)
		{
			toks = toks->next;
			//add to ast
			free(ft_lstpop(&syntax_vars->symbol_stack));
		}
		else
		{
			//look at production rules to create node of the tree.
			production = NULL;
			if (*symbol < NUM_NTS)
				production = tt[*symbol][((t_token *)toks->content)->tok_type - NUM_NTS];
			if (production)
				production(&syntax_vars->symbol_stack, ((t_token *)toks->content)->tok_type);
			else
				is_valid = 0;
		}
	}
	if (!is_valid)
		printf("syntax error near unexpected token `%s'\n", ((t_token *)toks->content)->text); //remove
	return (is_valid);
}

static void	ft_set_source(t_source *src, char *line)
{
	src->buffer = ft_strdup(line);
	src->bufsize = ft_strlen(line);
	src->curpos = INIT_SRC_POS;
}

static t_ast	ft_semantic(t_list *tokens)
{
	t_list		*command_list;
	t_list		*cmd_temp;

	command_list = NULL;
	ft_lstadd_back(&command_list, ft_lstnew(malloc(sizeof(t_command))));
	((t_command *)command_list->content)->cmd = NULL;
	ast->cmd = NULL;
	ast->children = 0;
	ast->first_child = NULL;
	ast->next_sibling = NULL;
	ast->prev_sibling = NULL;
	while (((t_token *)tokens->content)->tok_type != TS_EOF)
	{
		if (((t_token *)tokens->content)->tok_type == TS_WORD \
			|| ((t_token *)tokens->content)->tok_type != TS_ASSIGNMENT \
			|| ((t_token *)tokens->content)->tok_type != TS_LESS \
			|| ((t_token *)tokens->content)->tok_type != TS_DLESS \
			|| ((t_token *)tokens->content)->tok_type != TS_GREAT \
			|| ((t_token *)tokens->content)->tok_type != TS_DGREAT \
			|| ((t_token *)tokens->content)->tok_type != TS_LESSGREAT)
		{
			ast->type = AST_CMD;
			if (ast->cmd == NULL)
			{
				ast->cmd = (t_command *)malloc(sizeof(t_command));
				ast->cmd->assign = NULL;
				ast->cmd->cmd = NULL;
				ast->cmd->redir = NULL;
			}
			ast->type = AST_CMD;
			if (((t_token *)tokens->content)->tok_type == TS_WORD)
				ft_lstadd_back(&ast->cmd->cmd, ft_lstnew(tokens->content));
			else if (((t_token *)tokens->content)->tok_type == TS_ASSIGNMENT)
				ft_lstadd_back(&ast->cmd->assign, ft_lstnew(tokens->content));
			else
			{
				ft_lstadd_back(&ast->cmd->redir, ft_lstnew(tokens->content));
				tokens = tokens->next;
				ft_lstadd_back(&ast->cmd->redir, ft_lstnew(tokens->content));
			}
		}
		else
		{
			if (((t_token *)tokens->content)->tok_type == TS_PIPE \
			|| ((t_token *)tokens->content)->tok_type != TS_LBRACE \
			|| ((t_token *)tokens->content)->tok_type != TS_RBRACE \
			|| ((t_token *)tokens->content)->tok_type != TS_AND_IF \
			|| ((t_token *)tokens->content)->tok_type != TS_OR_IF)
			{

			}
		}
	}
}
