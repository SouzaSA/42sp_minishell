/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_expand_star.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:02:13 by edpaulin          #+#    #+#             */
/*   Updated: 2022/02/18 10:21:38 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

// char	*inputs[] = { "/", "/edpaulin/*/*/*/*/*", "/*", "./*", "/home/*/D*/*", 
// "home/minishell", "./*/*.c", "./../*", NULL };

static void		ft_print_list(t_list *list);

void	ft_test_expand_star(void)
{
	t_list		*list;
	const char	*inputs[] = {"/*/*/*/*/*/*/*", NULL};
	// const char	*inputs[] = {"/*/*/*/*", NULL};
	int			i;

	i = 0;
	ft_putendl_fd("===================================================\n", 1);
	while (inputs[i])
	{
		ft_putendl_fd("------------------------------------------------\n", 1);
		printf("input: [%s]\n", inputs[i]);
		printf("list: \n");
		list = ft_expand_star((char *)inputs[i]);
		if (!list)
			break ;
		ft_print_list(list);
		printf("\n\nList size = %d\n\n", ft_lstsize(list));
		ft_lstclear(&list, &ft_del_list_content);
		i++;
	}
	ft_putendl_fd("===================================================\n", 1);
}

static void	ft_print_list(t_list *list)
{
	t_list	*aux;

	if (!list)
		return ;
	aux = list;
	while (aux)
	{
		ft_putendl_fd((char *)aux->content, 1);
		aux = aux->next;
	}
}
