/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:06:49 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/05 09:33:30 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*msg;

	if (argc != 1 || !envp)
	{
		msg = ft_strjoin(argv[0], ": Invalid arguments.");
		printf("%s\n", msg);
		free(msg);
		return (1);
	}
	ft_minishell(envp);
	return (0);
}
