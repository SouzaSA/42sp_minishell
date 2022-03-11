/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:01:58 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/10 21:32:30 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

static void	ft_redir_msg_error(char *msg);
static void	ft_cmd_msg_error(char *msg);

int	ft_expand_error(char *msg, int type)
{
	if (type == FLAG_ERROR_REDIR)
		ft_redir_msg_error(msg);
	if (type == FLAG_ERROR_CMD)
		ft_cmd_msg_error(msg);
	return (1);
}

static void	ft_redir_msg_error(char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putendl_fd(": ambiguous redirect", 2);
}

static void	ft_cmd_msg_error(char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putendl_fd(": Argument list too long", 2);
}
