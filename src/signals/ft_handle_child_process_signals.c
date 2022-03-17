/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_child_process_signals.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:45:19 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/17 10:42:45 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_signals.h"

static void	ft_handle_sigint(void);
static void	ft_handle_sigquit(void);
static void	ft_process_cancel(int signal);
static void	ft_handle_sigusr1(void);
static void	ft_process_kill(int signal);

void	ft_handle_child_process_signals(void)
{
	ft_handle_sigint();
	ft_handle_sigquit();
	ft_handle_sigusr1();
}

static void	ft_handle_sigint(void)
{
	struct sigaction	sa;

	sa.sa_handler = &ft_process_cancel;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
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
	sigemptyset(&sa.sa_mask);
	sigaction(SIGQUIT, &sa, NULL);
}

static void	ft_handle_sigusr1(void)
{
	struct sigaction	sa;

	sa.sa_handler = &ft_process_kill;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
}

static void	ft_process_kill(int signal)
{
	if (signal)
		exit(0);
}
