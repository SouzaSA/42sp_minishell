/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_cmd_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:31:08 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/15 19:25:16 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_destroy_command(t_command **command)
{
	if (*command)
	{
		ft_lstclear(&((*command)->cmd), &free);
		ft_lstclear(&((*command)->redir), &free);
		ft_lstclear(&((*command)->assign), &free);
		free(*command);
		*command = NULL;
	}
}
