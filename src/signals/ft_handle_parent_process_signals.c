/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_parent_process_signals.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:55:35 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/06 15:37:15 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_signals.h"
#include "wait.h"

static void	ft_handle_sigint(void);
static void	ft_handle_sigquit(void);

void	ft_handle_parent_process_signals(void)
{
	ft_handle_sigint();
	ft_handle_sigquit();
}

static void	ft_handle_sigint(void)
{
	struct sigaction	sa;
	struct sigaction	old_sa;

	sa.sa_handler = &ft_att_status;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, &old_sa);
	sigaction(SIGINT, &old_sa, NULL);
}

static void	ft_handle_sigquit(void)
{
	struct sigaction	sa;
	struct sigaction	old_sa;

	sa.sa_handler = &ft_att_status;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGQUIT, &sa, &old_sa);
	sigaction(SIGQUIT, &old_sa, NULL);
}

