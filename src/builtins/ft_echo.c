/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:51:42 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/20 20:53:22 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_echo(t_list *cmd)
{
	int		i;
	int		flag;
	int		num_words;
	char	*word;
	t_list	*node;

	flag = 0;
	num_words = ft_lstsize(cmd);
	if (cmd->next && !ft_strcmp((char *)cmd->next->content, "-n"))
		flag = 1;
	i = 1 + flag;
	while (i < num_words)
	{
		word = ((char *)cmd->content)[i];
		write(1, word, ft_strlen(word));
		if (i < num_words - 1)
			write(1, " ", 1);
		i++;
	}
	if (flag == 0)
		write(1, "\n", 1);
}
