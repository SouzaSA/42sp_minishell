/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:19:35 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/02 18:19:36 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

void	ft_del_content_file_struct(void *content)
{
	ft_clean_file_struct((t_file *)content);
}

void	ft_del_content(void *content)
{
	free(content);
}
