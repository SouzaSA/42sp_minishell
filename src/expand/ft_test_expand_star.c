/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_expand_star.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:02:13 by edpaulin          #+#    #+#             */
/*   Updated: 2022/02/11 11:13:59 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

void	ft_test_expand_star(void)
{
	t_list	*list;
	char	*inputs[] = { "/", "/home/minishell", "home/minishell", "./", "././.", NULL };
	int		i;

	i = 0;
	while (inputs[i])
	{
		ft_putendl_fd("--------------------------------------------------------\n", 1);
		printf("input: [%s]\n", inputs[i]);
		printf("list: \n");
		list = ft_expand_star(inputs[i]);
		if (!list)
			break ;
		ft_lstclear(&list, &ft_del_list_content);
		i++;
	}
	ft_putendl_fd("========================================================\n", 1);
}
