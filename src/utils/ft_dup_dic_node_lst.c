/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_dic_node_lst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:09:34 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/05 11:29:59 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

t_list	*ft_dup_dic_node_lst(t_list *dic_node_lst)
{
	char			*new_key;
	char			*new_value;
	t_dictionary	*dic_iten;

	if (!dic_node_lst)
		return (NULL);
	dic_iten = malloc(sizeof(t_dictionary));
	new_key = ft_strdup(((t_dictionary *)dic_node_lst->content)->key);
	new_value = ft_strdup(((t_dictionary *)dic_node_lst->content)->value);
	if (!dic_iten || !new_key || !new_value)
	{
		free(dic_iten);
		free(new_key);
		free(new_value);
		return (NULL);
	}
	dic_iten->key = new_key;
	dic_iten->value = new_value;
	return (ft_lstnew(dic_iten));
}
