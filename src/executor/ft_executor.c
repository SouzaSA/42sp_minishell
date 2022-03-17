/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:45:35 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/17 10:40:56 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

static void	ft_init_exec_stack(t_ast *ast, t_list **cmd_stk, int level);
static int	ft_run_cmds(t_shell *shell, t_list **cmd_stk);
static int	ft_cmd_iter(t_shell *shell, t_cmd_data *data);
static void	ft_cmd_send(t_shell *shell, t_cmd_data *data, t_ast **ast);

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
		ft_init_exec_stack(ast, &cmd_stk, 0);
		ft_expand_tild(shell, cmd_stk);
		ft_expand_exit_num(cmd_stk);
		ft_expand_vars(shell, cmd_stk);
		ft_run_cmds(shell, &cmd_stk);
	}
	else
		rtn = 1;
	return (rtn);
}

static void	ft_init_exec_stack(t_ast *ast, t_list **cmd_stk, int level)
{
	if (!ast)
		return ;
	ast->level = level;
	if (ast->first_child)
		ft_init_exec_stack(ast->first_child->next_sibling, cmd_stk, level + 1);
	ft_lstpush(cmd_stk, ast);
	ft_init_exec_stack(ast->first_child, cmd_stk, level + 1);
}

static int	ft_run_cmds(t_shell *shell, t_list **cmd_stk)
{
	int			rtn;
	int			in_cpy;
	int			num_cmds;
	t_cmd_data	cmd_data;

	rtn = 0;
	in_cpy = dup(0);
	ft_cmd_data_init(&cmd_data, cmd_stk);
	num_cmds = ft_lstsize(*cmd_stk);
	if (num_cmds == 1)
		ft_single_buitin(shell, cmd_stk, &cmd_data);
	rtn = ft_cmd_iter(shell, &cmd_data);
	if (rtn && ft_lstsize(*cmd_stk))
		ft_destroy_ast_stk(cmd_stk);
	if ((num_cmds > 1 || !cmd_data.builtin_flag) && cmd_data.forked)
	{
		waitpid(cmd_data.pid, &rtn, 0);
		kill(cmd_data.pid, SIGUSR1);
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
	while (rtn == 0 && data->cmd_stk && ft_lstsize(*data->cmd_stk))
	{
		ast = (t_ast *)ft_lstpop(data->cmd_stk);
		if (ast->type == AST_CMD && shell)
			ft_cmd_send(shell, data, &ast);
		else if (ast->type == AST_PIPE)
			rtn = ft_pipe_run(data);
		if (ast)
		{
			if (ast->blk)
				ft_destroy_command(&ast->blk);
			free(ast);
		}
	}
	if (data->forked)
		close(data->pipe_fd[0]);
	return (rtn);
}

static void	ft_cmd_send(t_shell *shell, t_cmd_data *data, t_ast **ast)
{
	t_ast	*ast_nxt;

	ast_nxt = (t_ast *)ft_lsttop(*data->cmd_stk);
	data->pipe_flag = 0;
	if (ast_nxt && ast_nxt->type == AST_PIPE)
		data->pipe_flag = 1;
	data->cmd_stk = data->cmd_stk;
	if ((*ast)->blk->cmd && (*ast)->blk->cmd->content \
		&& ft_isbuiltin((char *)(*ast)->blk->cmd->content))
	{
		ft_builtin_run(shell, data, *ast);
	}
	else
	{
		ft_cmd_run(shell, data, *ast);
	}
	*ast = NULL;
}
