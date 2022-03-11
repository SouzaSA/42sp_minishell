/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_shell.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:30:26 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/05 11:42:09 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_destroy_shell(t_shell *shell)
{
	if (shell)
	{
		if (shell->env_list)
			ft_destroy_dictionary_list(&shell->env_list);
		if (shell->vars)
			ft_destroy_dictionary_list(&shell->vars);
		if (shell->transition_table)
			ft_destroy_tt(&shell->transition_table);
		if (shell->line)
			free(shell->line);
		shell->line = NULL;
	}
}
