/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:51:42 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/21 16:22:51 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_echo(t_list *cmds)
{
	int		i;
	int		flag;
	int		num_words;
	char	*word;
	t_list	*node;

	flag = 0;
	num_words = ft_lstsize(cmds);
	if (cmds->next && !ft_strcmp((char *)cmds->next->content, "-n"))
		flag = 1;
	i = 1 + flag;
	while (i < num_words)
	{
		word = ((char *)cmds->content)[i];
		write(1, word, ft_strlen(word));
		if (i < num_words - 1)
			write(1, " ", 1);
		i++;
	}
	if (flag == 0)
		write(1, "\n", 1);
}
