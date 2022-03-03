/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_cmd_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:31:08 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/03 18:35:46 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_destroy_command(t_cmd_blk **blk)
{
	if (*blk)
	{
		if ((*blk)->cmd)
		ft_lstclear(&((*blk)->cmd), &free);
		if ((*blk)->redir)
		ft_lstclear(&((*blk)->redir), &free);
		if ((*blk)->assign)
		ft_lstclear(&((*blk)->assign), &free);
		free(*blk);
		*blk = NULL;
	}
}
