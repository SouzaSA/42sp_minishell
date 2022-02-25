/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:45:35 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/24 20:28:23 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

static void ft_init_exec_stack(t_ast *ast, t_list **cmd_stk);
static int	ft_run_cmds(t_shell *shell, t_list **cmd_stk);

int	ft_executor(t_shell *shell, char *line)
{
	int		rtn;
	t_ast	*ast;
	t_list	*cmd_stk;

	rtn = 0;
	ast = NULL;
	cmd_stk = NULL;
	ast = ft_parser(line, shell->transition_table);
	if (ast)
	{
		ft_init_exec_stack(ast, &cmd_stk);
		ft_run_cmds(shell, &cmd_stk);
	}
	else
		rtn = 1;
	//if (ast) //remove, only to test leak
	//	ft_destroy_ast(&ast);//tirar
	return (rtn);
}

static void ft_init_exec_stack(t_ast *ast, t_list **cmd_stk)
{
	if (!ast)
		return ;
	if (ast->first_child)
		ft_init_exec_stack(ast->first_child->next_sibling, cmd_stk);
	ft_lstpush(cmd_stk, ast);
	ft_init_exec_stack(ast->first_child, cmd_stk);
}

static int	ft_run_cmds(t_shell *shell, t_list **cmd_stk)
{
	int			rtn;
	int			in_cpy;
	t_ast		*ast;
	t_ast		*ast_nxt;
	t_cmd_data	cmd_data;

	rtn = 0;
	in_cpy = dup(0);

	if (ft_lstsize(*cmd_stk) == 1)
	{
		ast = (t_ast *)ft_lsttop(*cmd_stk);
		if (ast->cmd && ast->cmd->cmd && ft_isbuiltin((char *)(ast->cmd->cmd->content)))
		{
			cmd_data.fd_in = 0;
			cmd_data.fd_out = 1;
			ast = ft_lstpop(cmd_stk);
			rtn = ft_assignments(shell, ast->cmd->assign);
			rtn = ft_redirections(ast->cmd->redir, &cmd_data.fd_in, &cmd_data.fd_out);
			ft_builin_parser(shell, ast->cmd);
			if (ast->cmd)
				ft_destroy_command(&ast->cmd);
			free(ast);
		}
	}
	else
	{
		while (rtn == 0 && ft_lstsize(*cmd_stk))
		{
			ast = (t_ast *)ft_lstpop(cmd_stk);
			if (ast->type == AST_CMD && shell)
			{
				ast_nxt = (t_ast *)ft_lsttop(*cmd_stk);
				cmd_data.pipe_flag = 0;
				if (ast_nxt && ast_nxt->type == AST_PIPE)
					cmd_data.pipe_flag = 1;
				cmd_data.cmd_stk = cmd_stk;
				if (ast->cmd->cmd && ast->cmd->cmd->content && ft_isbuiltin((char *)ast->cmd->cmd->content))
					ft_builtin_run(shell, &cmd_data, ast);
				else
					ft_cmd_run(shell, &cmd_data, ast);
				ast = NULL;
			}
			else if (ast->type == AST_PIPE)
				rtn = ft_pipe_run(&cmd_data);
			else if (ast->type == AST_AND || ast->type == AST_OR)
				rtn = ft_and_or_run(&cmd_data, ast->type);
			if (ast)
			{
				if (ast->cmd)
					ft_destroy_command(&ast->cmd);
				free(ast);
			}
		}
		if (rtn)
			ft_destroy_ast_stk(cmd_stk);
		if (cmd_data.pid > 0)
			waitpid(-1, NULL, 0);
		dup2(in_cpy, 0);
		close(in_cpy);
	}
	if (cmd_data.fd_out > 1)
		close(cmd_data.fd_out);
	return (rtn);
}
