/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbuiltin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:03:48 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/23 11:11:49 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtins.h"

int	ft_isbuiltin(char *cmd)
{
	int	is_builtin;

	is_builtin = 0;
	if (!ft_strcmp(cmd, "cd") || !ft_strcmp(cmd, "echo") \
		|| !ft_strcmp(cmd, "env") || !ft_strcmp(cmd, "exit") \
		|| !ft_strcmp(cmd, "export") || !ft_strcmp(cmd, "pwd") \
		|| !ft_strcmp(cmd, "unset"))
	{
		is_builtin = 1;
	}
	return (is_builtin);
}
