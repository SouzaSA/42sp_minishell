/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:45:35 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/19 21:03:47 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

static void ft_init_exec_stack(t_ast *ast, t_list **cmd_stk);
static int	ft_run_cmds(t_shell *shell, t_list **cmd_stk);
static int ft_and_or_run(t_cmd_data *cmd_data, enum e_ast_type type);
static int ft_pipe_run(t_cmd_data *cmd_data);

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
	while (rtn == 0 && ft_lstsize(*cmd_stk))
	{
		ast = (t_ast *)ft_lstpop(cmd_stk);
		if (ast->type == AST_CMD && shell)
		{
			ast_nxt = (t_ast *)ft_lsttop(*cmd_stk);
			cmd_data.pipe_flag = 0;
			if (ast_nxt && ast_nxt->type == AST_PIPE)
				cmd_data.pipe_flag = 1;
			rtn = ft_cmd_run(shell, &cmd_data, ast->cmd);
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
	{
		while (ft_lstsize(*cmd_stk))
			ft_lstpop(cmd_stk);
	}
	waitpid(-1, NULL, 0);
	close(cmd_data.pipe_fd[1]);
	dup2(in_cpy, 0);
	close(in_cpy);
	if (cmd_data.fd_out > 1)
		close(cmd_data.fd_out);
	return (rtn);
}

static int ft_and_or_run(t_cmd_data *cmd_data, enum e_ast_type type)
{
	int	rtn;
	int	wstatus;
	int	exec_status;

	rtn = 0;
	waitpid(cmd_data->pid, &wstatus, 0);
	exec_status = WEXITSTATUS(wstatus);
	close(cmd_data->pipe_fd[1]);
	close(cmd_data->pipe_fd[0]);
	if (cmd_data->fd_out > 1)
		close(cmd_data->fd_out);
	if ((!exec_status && type == AST_OR) || (exec_status && type == AST_AND))
		rtn = 1;
	return (rtn);
}

int ft_pipe_run(t_cmd_data *cmd_data)
{
	int	rtn;

	rtn = 0;
	close(cmd_data->pipe_fd[1]);
	waitpid(cmd_data->pid, NULL, 0);
	if (cmd_data->fd_out == 1)
		dup2(cmd_data->pipe_fd[0], 0);
	else if (cmd_data->fd_out > 1)
		close(cmd_data->fd_out);
	close(cmd_data->pipe_fd[0]);
	return (rtn);
}
