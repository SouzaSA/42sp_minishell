/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_here_doc_signals.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:11:18 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/05 14:17:08 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_signals.h"

static void	ft_here_doc_cancel(int signal);

void	ft_handle_here_doc_signals(int pid)
{
	if (pid == 0)
		signal(SIGINT, &ft_here_doc_cancel);
	else
		signal(SIGINT, SIG_IGN);
}

static void	ft_here_doc_cancel(int signal)
{
	g_exit_status = 128 + signal;
	write(1, "\n", 1);
	exit(130);
}
