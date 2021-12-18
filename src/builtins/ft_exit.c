/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:51:26 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/18 19:07:38 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

//	more than one argument:
//	|	exit
//	|	bash: exit: too many arguments

//	number greater than a long range
//	|	exit
//	|	bash: exit: 9223372036854775808: numeric argument required
//	return value (2)

void	ft_exit(long status, int flag)
{
	if (flag == 0)
		exit(EXIT_SHELL_SUCCESS);
	else
		exit(status);
}
