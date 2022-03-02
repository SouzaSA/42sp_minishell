/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:05:11 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/02 16:18:38 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtins.h"

int	ft_builin_parser(t_shell *shell, t_command *command)
{
	int		rtn;
	char	*cmd;

	rtn = 0;
	cmd = NULL;
	if (command && command->cmd)
		cmd = (char *)command->cmd->content;
	if (command && ft_strcmp(cmd, "cd") == 0)
		rtn = ft_cd(shell, command->cmd);
	else if (command && ft_strcmp(cmd, "echo") == 0)
		rtn = ft_echo(command->cmd);
	else if (command && ft_strcmp(cmd, "env") == 0)
		rtn = ft_env(shell);
	else if (command && ft_strcmp(cmd, "exit") == 0)
		rtn = ft_exit(shell, command->cmd);
	else if (command && ft_strcmp(cmd, "export") == 0)
		rtn = ft_export(shell, command->cmd);
	else if (command && ft_strcmp(cmd, "pwd") == 0)
		rtn = ft_pwd();
	else if (command && ft_strcmp(cmd, "unset") == 0)
		rtn = ft_unset(shell, command->cmd);
	shell->error_status = rtn;
	return (rtn);
}
