/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_dictionary_list.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:01:06 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/15 14:35:50 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_destroy_dictionary_list(t_list **dic_lst)
{
	ft_lstclear(dic_lst, &ft_destroy_dictionary_element);
	*dic_lst = NULL;
}
