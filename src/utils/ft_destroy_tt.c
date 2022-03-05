/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_tt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:29:04 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/05 11:48:09 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_destroy_tt(void (****transition_table)(t_list **, enum e_symbol))
{
	int	i;

	i = 0;
	if (*transition_table)
	{
		while (i < NUM_NTS)
		{
			free((*transition_table)[i]);
			i++;
		}
		free(*transition_table);
		*transition_table = NULL;
	}
}
