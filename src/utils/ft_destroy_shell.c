/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_shell.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:30:26 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/22 15:07:19 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_destroy_shell(t_shell *shell)
{
	int	i;

	if (shell)
	{
		i = 0;
		if (shell->env_list)
			ft_destroy_dictionary_list(&shell->env_list);
		if (shell->vars)
			ft_destroy_dictionary_list(&shell->vars);
		if (shell->transition_table)
		{
			while (i < NUM_NTS)
			{
				free(shell->transition_table[i]);
				i++;
			}
			free(shell->transition_table);
			shell->transition_table = NULL;
		}
	}
}
