/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:05:11 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/11 22:03:18 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtins.h"

static void	ft_quotes_cleaner(t_list *cmd);

int	ft_builin_parser(t_shell *shell, t_cmd_data *data, t_cmd_blk *blk)
{
	int		rtn;
	char	*cmd;

	rtn = 0;
	cmd = NULL;
	ft_quotes_cleaner(blk->cmd);
	if (blk && blk->cmd)
		cmd = (char *)blk->cmd->content;
	if (blk && ft_strcmp(cmd, "cd") == 0)
		rtn = ft_cd(shell, blk->cmd);
	else if (blk && ft_strcmp(cmd, "echo") == 0)
		rtn = ft_echo(blk->cmd);
	else if (blk && ft_strcmp(cmd, "env") == 0)
		rtn = ft_env(shell);
	else if (blk && ft_strcmp(cmd, "exit") == 0)
		rtn = ft_exit(shell, data, blk->cmd, blk);
	else if (blk && ft_strcmp(cmd, "export") == 0)
		rtn = ft_export(shell, blk->cmd);
	else if (blk && ft_strcmp(cmd, "pwd") == 0)
		rtn = ft_pwd();
	else if (blk && ft_strcmp(cmd, "unset") == 0)
		rtn = ft_unset(shell, blk->cmd);
	g_exit_status = rtn;
	return (rtn);
}

static void	ft_quotes_cleaner(t_list *cmd)
{
	char	*aux;

	while (cmd)
	{
		aux = (char *)cmd->content;
		cmd->content = ft_str_remove_quotes(aux);
		free(aux);
		cmd = cmd->next;
	}
}
