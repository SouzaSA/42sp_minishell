/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:05:11 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/21 19:40:58 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_builin_parser(t_shell *shell, t_command *command)
{
	int		rtn;
	char	*cmd;

	rtn = 0;
	cmd = NULL;
	if (command && command->cmd)
		cmd = (char *)command->cmd->content;
	if (command && ft_strcmp(cmd, "cd") == 0)
		ft_cd(shell, command->cmd);
	else if (command && ft_strcmp(cmd, "echo") == 0)
		ft_echo(command->cmd);
	else if (command && ft_strcmp(cmd, "env") == 0)
		ft_env(shell);
	else if (command && ft_strcmp(cmd, "exit") == 0)
		ft_exit(shell, command->cmd);
	else if (command && ft_strcmp(cmd, "export") == 0)
		ft_export(shell, command->assign);
	else if (command && ft_strcmp(cmd, "pwd") == 0)
		ft_pwd();
	else if (command && ft_strcmp(cmd, "unset") == 0)
		ft_unset(shell, command->cmd);
	return (rtn);
}
