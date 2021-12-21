/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_msg_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:10:27 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/21 08:48:54 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_put_msg_error(t_shell *shell, char *msg, int error_flag)
{
	shell->error_status == 1;
	ft_putstr_fd("minishell: ", 2);
	if (error_flag == 1 && !msg)
		ft_putendl_fd(strerror(shell->error_status), 2);
	else if (error_flag == 1)
		ft_putendl_fd(msg, 2);
	else
		perror(msg);
	return (1);
}
