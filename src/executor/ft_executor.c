/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:45:35 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/15 21:40:45 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"
/*****PRINTAST**********/

static void ft_imprime(t_ast *ast) //remove, test only
{
	printf("t: %d, c: %d\n", ast->type, ast->children);
	if (ast->type == AST_PIPE)
		printf(" | ");
	else if (ast->type == AST_AND)
		printf(" && ");
	else if (ast->type == AST_OR)
		printf(" || ");
	else if (ast->type == AST_CMD)
	{
		printf(" Command: ");
		while (ast->cmd->cmd)
		{
			printf(" %s ", (char *)ast->cmd->cmd->content);
			ast->cmd->cmd = ast->cmd->cmd->next;
		}
		printf(", Assign: ");
		while (ast->cmd->assign)
		{
			printf(" %s ", (char *)ast->cmd->assign->content);
			ast->cmd->assign = ast->cmd->assign->next;
		}
		printf(", Redir: ");
		while (ast->cmd->redir)
		{
			printf(" %s ", (char *)ast->cmd->redir->content);
			ast->cmd->redir = ast->cmd->redir->next;
		}
	}
	printf("\n");
}

static void printlist(t_list **list) //remove, test only
{
	t_ast	*node;
	t_list	*list_node_tmp;

	if (*list)
	{
		if ((*list)->content)
		{
			list_node_tmp = *list;
			node = (*list)->content;
			ft_imprime(node);
			node = node->first_child;
			while (node)
			{
				ft_lstadd_back(list, ft_lstnew(node));
				node = node->next_sibling;
			}
			*list = (*list)->next;
			printlist(list);
			free(list_node_tmp);
		}
	}
}

static void ft_printast(t_ast *ast) //remove, test only
{
	t_list *list;

	list = NULL;
	if (ast)
	{
		ft_lstadd_back(&list, ft_lstnew(ast));
		printlist(&list);
	}
}
/**********************/
int	ft_executor(t_shell *shell, t_ast *ast)
{
	int		rtn;
	t_list	*cmd_stk;

	cmd_stk = NULL;
	ft_init_exec_stack(ast, &cmd_stk);
	ft_run_cmds(shell, &cmd_stk);
	return (rtn);
}

static void ft_init_exec_stack(t_ast *ast, t_list **cmd_stk)
{
	ft_init_exec_stack(ast->next_sibling, cmd_stk);
	ft_init_exec_stack(ast->first_child, cmd_stk);
	ft_lstpush(cmd_stk, ast);
}

static int	ft_run_cmds(t_shell *shell, t_list **cmd_stk)
{
	int			rtn;
	t_ast		*ast;
	t_cmd_data	cmd_data;

	rtn = 0;
	while (*cmd_stk)
	{
		ast = (t_ast *)ft_lstpop(cmd_stk);
		if (ast->type == AST_CMD)
			rtn = ft_cmd_run(shell, &cmd_data, ast->cmd);
		if (ast->type == AST_PIPE)
			rtn = ft_pipe_run(shell, &cmd_data, ast->cmd);
		if (ast->type == AST_AND || ast->type == AST_OR)
			rtn = ft_and_or_run(shell, &cmd_data, ast->cmd);
	}
	return (rtn);
}

int ft_and_or_run(t_shell *shell, t_cmd_data *cmd_data, t_command *cmd)
{
	int	rtn;
	int status;

	waitpid(cmd_data->pid, &status, 0);
	//TODO -> quit when necessary
	if (status == 0)
	return(rtn);
}

int ft_pipe_run(t_shell *shell, t_cmd_data *cmd_data, t_command *cmd)
{
	int	rtn;

	return(rtn);
}
