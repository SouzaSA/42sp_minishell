/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_signals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:23:12 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/17 16:31:54 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"
#include <signal.h>

void	ft_handle_sigint(int signal)
{
	if (signal)
		printf("\n\033[0;33m$\e[0;39m ");
}

void	ft_handle_sigquit(int signal)
{
	if (signal)
		return ;
}
