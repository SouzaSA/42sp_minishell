/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_process_signals.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:23:12 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/05 11:24:09 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_signals.h"

void	ft_process_cancel(int signal);
void	ft_process_quit(int signal);

void	ft_handle_process_signals(void)
{
	signal(SIGINT, &ft_process_cancel);
	signal(SIGQUIT, &ft_process_quit);
}

void	ft_process_cancel(int signal)
{
	if (signal)
		write(1, "\n", 1);
}

void	ft_process_quit(int signal)
{
	if (signal)
		ft_putendl_fd("Quit (core dump)", 1);
}
