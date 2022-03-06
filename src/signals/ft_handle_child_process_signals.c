/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_child_process_signals.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:45:19 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/06 16:05:32 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_signals.h"

static void	ft_handle_sigint(void);
static void	ft_handle_sigquit(void);

static void	ft_process_cancel(int signal);

void	ft_handle_child_process_signals(void)
{
	ft_handle_sigint();
	ft_handle_sigquit();
}

static void	ft_handle_sigint(void)
{
	struct sigaction	sa;

	sa.sa_handler = &ft_process_cancel;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
}

static void	ft_process_cancel(int signal)
{
	exit(128 + signal);
}

static void	ft_handle_sigquit(void)
{
	struct sigaction	sa;

	sa.sa_handler = SIG_DFL;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGQUIT, &sa, NULL);
}
