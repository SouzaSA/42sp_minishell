/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and_or_run_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:00:20 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/15 19:20:26 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

static void	ft_remove_unused_branch(t_cmd_data *data);

int	ft_and_or_run(t_cmd_data *data, enum e_ast_type type)
{
	int		wstatus;
	int		exec_status;

	exec_status = data->last_status;
	if (data->forked)
	{
		waitpid(data->pid, &wstatus, 0);
		exec_status = WEXITSTATUS(wstatus);
		close(data->pipe_fd[0]);
	}
	if (data->fd_out > 1)
		close(data->fd_out);
	if ((!exec_status && type == AST_OR) || (exec_status && type == AST_AND))
		ft_remove_unused_branch(data);
	data->forked = 0;
	data->last_status = exec_status;
	g_exit_status = exec_status;
	return (exec_status);
}

static void	ft_remove_unused_branch(t_cmd_data *data)
{
	int		level;
	t_ast	*ast;

	ast = (t_ast *)ft_lsttop(*data->cmd_stk);
	level = ast->level - 1;
	while (ast && ast->level > level)
	{
		ast = (t_ast *)ft_lstpop(data->cmd_stk);
		if (ast->blk)
			ft_destroy_command(&ast->blk);
		free(ast);
		ast = (t_ast *)ft_lsttop(*data->cmd_stk);
	}
}
