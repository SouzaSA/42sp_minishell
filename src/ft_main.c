/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:06:49 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/16 09:41:46 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*msg;

	if (argc != 1)
	{
		msg = ft_strjoin(argv[0], ": Invalid arguments.");
		printf("%s\n", msg);
		free(msg);
		return (1);
	}
	//signal(SIGINT, &ft_handle_sigint);
	//signal(SIGQUIT, &ft_handle_sigquit);
	//ft_test_expand_star();
	ft_minishell(envp);
	return (0);
}
