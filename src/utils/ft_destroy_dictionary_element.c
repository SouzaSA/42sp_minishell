/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_dictionary_element.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:51:29 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/18 16:52:23 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_destroy_dictionary_element(void *dic_item)
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
