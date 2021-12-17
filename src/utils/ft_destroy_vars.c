/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_vars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:01:06 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/16 20:23:07 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static	void	ft_destroy_dictionary(void *dic_item);

void	ft_destroy_vars(t_shell *shell)
{
	ft_lstclear(&shell->env_list, &ft_destroy_dictionary);
}

static	void	ft_destroy_dictionary(void *dic_item)
{
	t_dictionary	*aux;

	if (dic_item)
	{
		aux = (t_dictionary *)dic_item;
		if (aux->key)
			free(aux->key);
		aux->key = NULL;
		if (aux->value)
			free(aux->value);
		aux->key = NULL;
		free(dic_item);
	}
}
