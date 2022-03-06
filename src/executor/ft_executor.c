/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:45:35 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/06 15:56:02 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

static void	ft_init_exec_stack(t_ast *ast, t_list **cmd_stk);
static int	ft_run_cmds(t_shell *shell, t_list **cmd_stk);
static int	ft_cmd_iter(t_shell *shell, t_cmd_data *data);
static void	ft_cmd_send(t_shell *shell, t_cmd_data *data, t_ast *ast);

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
		ft_expand_tild(shell, cmd_stk);
		ft_expand_exit_num(cmd_stk);
		ft_expand_vars(shell, cmd_stk);
		ft_run_cmds(shell, &cmd_stk);
	}
	else
		rtn = 1;
	return (rtn);
}

static void	ft_init_exec_stack(t_ast *ast, t_list **cmd_stk)
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
	t_cmd_data	cmd_data;

	rtn = 0;
	in_cpy = dup(0);
	ft_cmd_data_init(&cmd_data, cmd_stk);
	if (ft_lstsize(*cmd_stk) == 1)
		ft_single_buitin(shell, cmd_stk, &cmd_data);
	rtn = ft_cmd_iter(shell, &cmd_data);
	if (rtn && ft_lstsize(*cmd_stk))
		ft_destroy_ast_stk(cmd_stk);
	if (!cmd_data.builtin_flag && cmd_data.pid > 0)
	{
		waitpid(-1, &rtn, 0);
		if (!WIFSIGNALED(rtn))
			g_exit_status = WEXITSTATUS(rtn);
	}
	dup2(in_cpy, 0);
	close(in_cpy);
	if (cmd_data.fd_out > 1)
		close(cmd_data.fd_out);
	return (rtn);
}

static int	ft_cmd_iter(t_shell *shell, t_cmd_data *data)
{
	int			rtn;
	t_ast		*ast;

	rtn = 0;
	while (rtn == 0 && ft_lstsize(*data->cmd_stk))
	{
		ast = (t_ast *)ft_lstpop(data->cmd_stk);
		if (ast->type == AST_CMD && shell)
		{
			ft_cmd_send(shell, data, ast);
			ast = NULL;
		}
		else if (ast->type == AST_PIPE)
			rtn = ft_pipe_run(data);
		else if (ast->type == AST_AND || ast->type == AST_OR)
			rtn = ft_and_or_run(data, ast->type);
		if (ast)
		{
			if (ast->blk)
				ft_destroy_command(&ast->blk);
			free(ast);
		}
	}
	return (rtn);
}

static void	ft_cmd_send(t_shell *shell, t_cmd_data *data, t_ast *ast)
{
	t_ast	*ast_nxt;

	ast_nxt = (t_ast *)ft_lsttop(*data->cmd_stk);
	data->pipe_flag = 0;
	if (ast_nxt && ast_nxt->type == AST_PIPE)
		data->pipe_flag = 1;
	data->cmd_stk = data->cmd_stk;
	if (ast->blk->cmd && ast->blk->cmd->content \
		&& ft_isbuiltin((char *)ast->blk->cmd->content))
	{
		ft_builtin_run(shell, data, ast);
	}
	else
	{
		ft_cmd_run(shell, data, ast);
	}
}
