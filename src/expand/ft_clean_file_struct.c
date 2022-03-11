/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_file_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:19:30 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/02 18:19:54 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

void	ft_clean_file_struct(t_file *fl)
{
	if (fl->name)
		free(fl->name);
	fl->name = NULL;
	free(fl);
}
