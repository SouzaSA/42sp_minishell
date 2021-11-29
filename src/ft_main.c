/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:06:49 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/26 09:18:22 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	minishell(char **envp)
{

	return (0);
}

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
	minishell(envp);
	return (0);
}
