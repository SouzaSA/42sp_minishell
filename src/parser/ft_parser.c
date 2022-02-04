/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:18:16 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/04 11:01:27 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static t_ast	*ft_syntax(t_list *toks, void (***tt)(t_list **, enum e_symbol));
static void		ft_set_source(t_source *src, char *line);

t_ast	*ft_parser(char *line, void	(***tt)(t_list **, enum e_symbol))
{
	t_ast		*ast;
	t_list		*tokens;
	t_source	src;

	ast = NULL;
	ft_set_source(&src, line);
	tokens = ft_lexer(&src);
	if (ft_syntax(tokens, tt))
		printf("deu certo\n");
	return (ast);
}

static t_ast	*ft_syntax(t_list *toks, void (***tt)(t_list **, enum e_symbol))
{
	t_ast		*ast;
	t_list		*symbol_stack;
	void		(*production)(t_list **, enum e_symbol);
	t_stk_node	*stk_node;
	int			is_valid;

	ast = ft_new_node(AST_TMP);
	symbol_stack = NULL;
	ft_lstpush(&symbol_stack, ft_stk_node(TS_EOF));
	ft_lstpush(&symbol_stack, ft_stk_node(NTS_START));
	((t_stk_node *)symbol_stack->content)->ast_node = ast;
	is_valid = 1;
	while (is_valid && ft_lstsize(symbol_stack) > 0)
	{
		stk_node = (t_stk_node *)ft_lsttop(symbol_stack);
		if (((t_token *)toks->content)->tok_type == stk_node->stk_type)
		{
			if ((stk_node->ast_type == AST_CMD || stk_node->ast_type == AST_ASSIGN || stk_node->ast_type == AST_REDIR) && stk_node->ast_node && !stk_node->ast_node->cmd)
			{
				stk_node->ast_node->cmd = (t_command *)malloc(sizeof(t_command));
				stk_node->ast_node->cmd->cmd = NULL;
				stk_node->ast_node->cmd->redir = NULL;
				stk_node->ast_node->cmd->assign = NULL;
			}
			if (stk_node->ast_type == AST_CMD)
				ft_lstadd_back(&stk_node->ast_node->cmd->cmd, ft_lstnew(((t_token *)toks->content)->text));
			if (stk_node->ast_type == AST_ASSIGN)
				ft_lstadd_back(&stk_node->ast_node->cmd->assign, ft_lstnew(((t_token *)toks->content)->text));
			if (stk_node->ast_type == AST_REDIR)
				ft_lstadd_back(&stk_node->ast_node->cmd->redir, ft_lstnew(((t_token *)toks->content)->text));
			toks = toks->next;
			free(ft_lstpop(&symbol_stack));
		}
		else
		{
			//look at production rules to create node of the tree.
			production = NULL;
			if (stk_node->stk_type < NUM_NTS)
				production = tt[stk_node->stk_type][((t_token *)toks->content)->tok_type - NUM_NTS];
			if (production)
				production(&symbol_stack, ((t_token *)toks->content)->tok_type);
			else
				is_valid = 0;
		}
	}
	if (!is_valid)
		printf("syntax error near unexpected token `%s'\n", ((t_token *)toks->content)->text); //remove
	return (ast);
}

static void	ft_set_source(t_source *src, char *line)
{
	src->buffer = ft_strdup(line);
	src->bufsize = ft_strlen(line);
	src->curpos = INIT_SRC_POS;
}
