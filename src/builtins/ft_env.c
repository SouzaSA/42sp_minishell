/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 09:45:11 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/18 14:27:23 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void	ft_print_dictionary(void *dic_item);

int	ft_env(t_shell *shell)
{
	if (shell && shell->env_list)
	{
		ft_lstiter(shell->env_list, &ft_print_dictionary);
		shell->error_status = EXIT_SHELL_SUCCESS;
	}
	return (0);
}

static void	ft_print_dictionary(void *dic_item)
{
	if (dic_item)
	{
		if (((t_dictionary *)dic_item)->key)
			ft_putstr_fd(((t_dictionary *)dic_item)->key, 1);
		write(1, "=", 1);
		if (((t_dictionary *)dic_item)->value)
			ft_putendl_fd(((t_dictionary *)dic_item)->value, 1);
	}
}
