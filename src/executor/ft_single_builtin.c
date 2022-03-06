/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_single_builtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:58:54 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/06 15:16:18 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

void	ft_single_buitin(t_shell *shell, t_list **cmd_stk, t_cmd_data *data)
{
	t_ast		*ast;
	t_cmd_blk	*blk;

	ast = (t_ast *)ft_lsttop(*cmd_stk);
	blk = ast->blk;
	if (blk && blk->cmd && ft_isbuiltin((char *)(blk->cmd->content)))
	{
		data->builtin_flag = 1;
		ast = ft_lstpop(cmd_stk);
		ft_assignments(shell, blk->assign);
		ft_redirections(shell, blk->redir, &data->fd_in, &data->fd_out);
		free(ast);
		ft_builin_parser(shell, data, blk);
		if (blk)
			ft_destroy_command(&blk);
	}
}
