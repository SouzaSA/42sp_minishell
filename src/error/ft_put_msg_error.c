/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_msg_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:10:27 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/22 11:48:46 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

int	ft_put_msg_error(char *msg, int error_flag)
{
	ft_putstr_fd("minishell: ", 2);
	if (error_flag == FLAG_ERROR_PERROR)
	{
		perror(msg);
	}
	else if (error_flag == FLAG_ERROR_STRERROR)
	{
		ft_putstr_fd(msg, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(g_errnum), 2);
	}
	else if (error_flag == FLAG_ERROR_HOMEMADE)
	{
		ft_putendl_fd(msg, 2);
	}
	return (1);
}
