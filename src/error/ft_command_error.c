/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:38:11 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/11 20:38:59 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

void	ft_command_error(char *cmd_name)
{
	char	*return_msg;

	return_msg = ft_strjoin(cmd_name, ": command not found");
	ft_put_msg_error(return_msg, FLAG_ERROR_OWN);
	free(return_msg);
	g_exit_status = 127;
}
