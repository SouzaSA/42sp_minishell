/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:51:26 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/14 16:52:14 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtins.h"

static int	ft_is_num(char *num);
static int	ft_exit_messages(int code, char *msg, int flag);

int	ft_exit(t_shell *shell, t_cmd_data *data, t_list *cmds, t_cmd_blk *blk)
{
	int	rtn;
	int	len;

	rtn = 0;
	len = ft_lstsize(cmds);
	if (len >= 2 && !ft_is_num((char *)cmds->next->content))
		rtn = ft_exit_messages(2, (char *)cmds->next->content, 2);
	else if (len > 2)
		rtn = ft_exit_messages(1, NULL, 1);
	else if (len == 2)
		rtn = ft_exit_messages(ft_atoi((char *)cmds->next->content), NULL, 0);
	else
		rtn = ft_exit_messages(0, NULL, 0);
	g_exit_status = rtn;
	if (rtn != 2)
	{
		if (ft_lstsize(*data->cmd_stk))
			ft_destroy_ast_stk(data->cmd_stk);
		ft_destroy_command(&blk);
		rl_clear_history();
		ft_destroy_shell(shell);
		exit(rtn);
	}
	return (rtn);
}

static int	ft_is_num(char *num)
{
	int	i;
	int	is_digit;

	i = 0;
	is_digit = 1;
	while (is_digit && num[i])
	{
		if (!ft_isdigit(num[i]) && num[0] != '+' && num[0] != '-')
			is_digit = 0;
		i++;
	}
	return (is_digit);
}

static int	ft_exit_messages(int code, char *msg, int flag)
{
	int	rtn;

	if (flag == 0)
	{
		rtn = g_exit_status;
		ft_putendl_fd("exit", 2);
	}
	else if (flag == 1)
	{
		rtn = 1;
		ft_putendl_fd("minishell: exit: too many arguments", 2);
	}
	else if (flag == 2)
	{
		rtn = 2;
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(msg, 2);
		ft_putendl_fd(": numeric argument required", 2);
	}
	else
	{
		rtn = code % 256;
		ft_putendl_fd("exit", 2);
	}
	return (rtn);
}
