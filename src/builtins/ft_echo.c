/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:51:42 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/15 19:08:59 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtins.h"

int	ft_echo(t_list *cmds)
{
	int		i;
	int		flag;
	int		num_words;
	char	*word;

	flag = 0;
	num_words = ft_lstsize(cmds);
	if (cmds->next && !ft_strcmp((char *)cmds->next->content, "-n"))
		flag = 1;
	i = 1 + flag;
	cmds = cmds->next;
	if (flag)
		cmds = cmds->next;
	while (cmds && i < num_words)
	{
		word = ((char *)cmds->content);
		write(1, word, ft_strlen(word));
		if (i < num_words - 1)
			write(1, " ", 1);
		cmds = cmds->next;
		i++;
	}
	if (flag == 0)
		write(1, "\n", 1);
	return (0);
}
