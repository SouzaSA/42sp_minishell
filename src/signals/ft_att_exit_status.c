/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_att_exit_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:35:41 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/13 17:48:06 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_signals.h"

void	ft_att_exit_status(int signal)
{
	g_exit_status = (128 + signal);
	if (signal == SIGQUIT)
		write(1, "Quit", 5);
	write(1, "\n", 1);
}
