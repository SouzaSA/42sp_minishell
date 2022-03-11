/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and_or_run.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:00:20 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/05 11:31:53 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

int	ft_and_or_run(t_cmd_data *data, enum e_ast_type type)
{
	int	rtn;
	int	wstatus;
	int	exec_status;

	rtn = 0;
	waitpid(data->pid, &wstatus, 0);
	exec_status = WEXITSTATUS(wstatus);
	close(data->pipe_fd[0]);
	if (data->fd_out > 1)
		close(data->fd_out);
	if ((!exec_status && type == AST_OR) || (exec_status && type == AST_AND))
		rtn = 1;
	return (rtn);
}
