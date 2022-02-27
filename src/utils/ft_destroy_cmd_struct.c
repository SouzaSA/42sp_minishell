/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_cmd_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:31:08 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/26 19:21:25 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_destroy_command(t_command **command)
{
	if (*command)
	{
		if ((*command)->cmd)
		ft_lstclear(&((*command)->cmd), &free);
		if ((*command)->redir)
		ft_lstclear(&((*command)->redir), &free);
		if ((*command)->assign)
		ft_lstclear(&((*command)->assign), &free);
		free(*command);
		*command = NULL;
	}
}
