/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 09:51:10 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/03 18:35:16 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static void	ft_term_prod(t_list **toks, t_stk_node *node, t_list **cmd_stk);
static int	ft_nonterm_prod(t_list *toks, t_stk_node *node, t_list **cmd_stk, \
	void (***tt)(t_list **, enum e_symbol));
static void	ft_clean_ast(t_ast **ast);

t_ast	*ft_syntax(t_list *toks, void (***tt)(t_list **, enum e_symbol))
{
	t_ast		*ast;
	t_list		*command_stk;
	t_stk_node	*stk_node;
	int			is_valid;

	ast = ft_new_node(AST_TMP);
	command_stk = NULL;
	ft_lstpush(&command_stk, ft_stk_node(TS_EOF));
	ft_lstpush(&command_stk, ft_stk_node(NTS_START));
	((t_stk_node *)command_stk->content)->ast_node = ast;
	is_valid = 1;
	while (is_valid && ft_lstsize(command_stk) > 0)
	{
		stk_node = (t_stk_node *)ft_lsttop(command_stk);
		if (((t_token *)toks->content)->type == stk_node->stk_type)
			ft_term_prod(&toks, stk_node, &command_stk);
		else
			is_valid = ft_nonterm_prod(toks, stk_node, &command_stk, tt);
	}
	if (!is_valid)
	{
		ft_parser_error_msg(((t_token *)toks->content)->text);
		ft_destroy_ast(&ast);
	}
	ft_clean_ast(&ast);
	return (ast);
}

static void	ft_term_prod(t_list **toks, t_stk_node *node, t_list **cmd_stk)
{
	if ((node->ast_type == AST_CMD || node->ast_type == AST_ASSIGN \
		|| node->ast_type == AST_REDIR) && node->ast_node && \
		!node->ast_node->blk)
	{
		node->ast_node->blk = (t_cmd_blk *)malloc(sizeof(t_cmd_blk));
		node->ast_node->blk->cmd = NULL;
		node->ast_node->blk->redir = NULL;
		node->ast_node->blk->assign = NULL;
	}
	if (node->ast_type == AST_CMD)
		ft_lstadd_back(&node->ast_node->blk->cmd, \
		ft_lstnew(ft_strdup(((t_token *)(*toks)->content)->text)));
	if (node->ast_type == AST_ASSIGN)
		ft_lstadd_back(&node->ast_node->blk->assign, \
		ft_lstnew(ft_strdup(((t_token *)(*toks)->content)->text)));
	if (node->ast_type == AST_REDIR)
		ft_lstadd_back(&node->ast_node->blk->redir, \
		ft_lstnew(ft_strdup(((t_token *)(*toks)->content)->text)));
	*toks = (*toks)->next;
	free(ft_lstpop(cmd_stk));
}

static int	ft_nonterm_prod(t_list *toks, t_stk_node *node, t_list **cmd_stk, \
	void (***tt)(t_list **, enum e_symbol))
{
	int				is_valid;
	void			(*production)(t_list **, enum e_symbol);
	enum e_symbol	token_type;

	is_valid = 1;
	production = NULL;
	token_type = ((t_token *)toks->content)->type;
	if (node->stk_type < NUM_NTS)
		production = tt[node->stk_type][token_type - NUM_NTS];
	if (production)
		production(cmd_stk, ((t_token *)toks->content)->type);
	else
		is_valid = 0;
	if (!is_valid)
	{
		while (ft_lstsize(*cmd_stk) > 0)
			free(ft_lstpop(cmd_stk));
	}
	return (is_valid);
}

static void	ft_clean_ast(t_ast **ast)
{
	t_ast	*ast_tmp;

	if (*ast)
	{
		ft_clean_ast(&(*ast)->next_sibling);
		ft_clean_ast(&(*ast)->first_child);
	}
	if ((*ast) && (*ast)->children == 1)
	{
		ast_tmp = *ast;
		*ast = (*ast)->first_child;
		(*ast)->next_sibling = ast_tmp->next_sibling;
		(*ast)->prev_sibling = ast_tmp->prev_sibling;
		free(ast_tmp);
	}
}
