/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_single_builtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:58:54 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/08 15:48:39 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

static void	ft_change_std_in_out(t_cmd_data *data);
static void	ft_close_fds(t_cmd_data *data, int in_dup, int out_dup);

void	ft_single_buitin(t_shell *shell, t_list **cmd_stk, t_cmd_data *data)
{
	int			in_dup;
	int			out_dup;
	t_ast		*ast;
	t_cmd_blk	*blk;

	ast = (t_ast *)ft_lsttop(*cmd_stk);
	blk = ast->blk;
	data->blk = blk;
	if (blk && blk->cmd && ft_isbuiltin((char *)(blk->cmd->content)))
	{
		ft_assignments(shell, blk->assign);
		ft_redirections(shell, data);
		in_dup = dup(0);
		out_dup = dup(1);
		ft_change_std_in_out(data);
		data->builtin_flag = 1;
		ast = ft_lstpop(cmd_stk);
		free(ast);
		ft_builin_parser(shell, data, blk);
		if (blk)
			ft_destroy_command(&blk);
		ft_close_fds(data, in_dup, out_dup);
	}
}

static void	ft_change_std_in_out(t_cmd_data *data)
{
	if (data->fd_in > 0)
		dup2(data->fd_in, 0);
	if (data->fd_out > 1)
		dup2(data->fd_out, 1);
}

static void	ft_close_fds(t_cmd_data *data, int in_dup, int out_dup)
{
	if (data->fd_in > 0)
		close(data->fd_in);
	if (data->fd_out > 1)
		close(data->fd_out);
	dup2(in_dup, 0);
	dup2(out_dup, 1);
	clear_history();
}
