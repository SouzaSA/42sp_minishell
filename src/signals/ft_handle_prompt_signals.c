/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_prompt_signals.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:56:26 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/06 17:10:28 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_signals.h"

static void	ft_handle_sigint(void);
static void	ft_prompt_cancel(int signal);
static void	ft_handle_sigquit(void);

void	ft_handle_prompt_signals(void)
{
	ft_handle_sigint();
	ft_handle_sigquit();
}

static void	ft_handle_sigint(void)
{
	struct sigaction	sa;

	sa.sa_handler = &ft_prompt_cancel;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
}

static void	ft_prompt_cancel(int signal)
{
	g_exit_status = (128 + signal);
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

static void	ft_handle_sigquit(void)
{
	struct sigaction	sa;

	sa.sa_handler = SIG_IGN;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGQUIT, &sa, NULL);
}
