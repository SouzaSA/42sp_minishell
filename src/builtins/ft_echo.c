/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:51:42 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/18 16:56:14 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_echo(char *str, int flag)
{
	if (flag == 0)
		ft_putendl_fd(str, 1);
	else
		ft_putstr_fd(str, 1);
}
