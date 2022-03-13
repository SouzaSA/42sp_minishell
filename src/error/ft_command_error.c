/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:38:11 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/13 20:47:57 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

void	ft_command_error(char *cmd_name, int flag)
{
	char	*return_msg;

	if (flag == 1)
		return_msg = ft_strjoin(cmd_name, ": Is a directory");
	else
		return_msg = ft_strjoin(cmd_name, ": command not found");
	ft_put_msg_error(return_msg, FLAG_ERROR_OWN);
	free(return_msg);
	g_exit_status = (127 - flag);
}
