/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:51:26 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/25 11:38:41 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtins.h"

static int	ft_is_num(char *num);

int	ft_exit(t_shell *shell, t_list *cmds)
{
	int	rtn;
	int	len;

	rtn = 2;
	len = ft_lstsize(cmds);
	shell->error_status = 1;
	ft_putstr_fd("exit ", 2);
	if (len > 2)
	{
		shell->error_status = 2;
		ft_putendl_fd("minishell: exit: too many arguments", 2);
	}
	else if (len == 2 && !ft_is_num((char *)cmds->next->content))
	{
		rtn = 2;
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd((char *)cmds->next->content, 2);
		ft_putendl_fd(": numeric argument required", 2);
	}
	else if (len == 2)
		rtn = ft_atoi((char *)cmds->next->content) % 256;
	else
		rtn = 0;
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
		if (!ft_isdigit(num[i]) || num[0] == '+' || num[0] == '-')
			is_digit = 0;
		i++;
	}
	return (is_digit);
}
