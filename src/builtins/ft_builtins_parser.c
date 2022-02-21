/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:05:11 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/20 20:59:06 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_builin_parser(t_list *cmd)
{
	int	rtn;

	rtn = 0;
	if (ft_strcmp((char *)cmd->content, "cd") == 0);
	else if (ft_strcmp((char *)cmd->content, "echo") == 0);
	else if (ft_strcmp((char *)cmd->content, "env") == 0);
	else if (ft_strcmp((char *)cmd->content, "exit") == 0);
	else if (ft_strcmp((char *)cmd->content, "export") == 0);
	else if (ft_strcmp((char *)cmd->content, "pwd") == 0);
	else if (ft_strcmp((char *)cmd->content, "unset") == 0);
	return (rtn);
}
