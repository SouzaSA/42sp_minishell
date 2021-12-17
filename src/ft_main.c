/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:06:49 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/16 20:29:58 by sde-alva         ###   ########.fr       */
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
	ft_minishell(envp);
	return (0);
}
