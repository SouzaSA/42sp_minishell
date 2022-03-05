/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_prompt_signals.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:56:26 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/05 11:24:09 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_signals.h"

void	ft_prompt_cancel(int signal);

void	ft_handle_prompt_signals(void)
{
	signal(SIGINT, &ft_prompt_cancel);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_prompt_cancel(int signal)
{
	if (signal)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}
