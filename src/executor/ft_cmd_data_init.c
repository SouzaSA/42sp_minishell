/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_data_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:11:36 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/15 21:46:52 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

void	ft_cmd_data_init(t_cmd_data *data, t_list **cmd_stk)
{
	data->fd_in = 0;
	data->fd_out = 1;
	data->builtin_flag = 0;
	data->pid = -1;
	data->forked = 0;
	data->last_status = 0;
	data->cmd_stk = cmd_stk;
	data->in_cpy = dup(0);
}
