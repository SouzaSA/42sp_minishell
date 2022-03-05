/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_exit_num.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 09:06:49 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/05 11:30:13 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

void	ft_expand_exit_num(t_shell *shell, t_cmd_blk *blk)
{
	ft_change_symbol(shell, &blk->assign);
	ft_change_symbol(shell, &blk->cmd);
	ft_change_symbol(shell, &blk->redir);
}

static void	ft_change_symbol(t_shell *shell, t_list **list)
{
	char	*aux;
	t_list	*node;

	node = *list;
	while (node)
	{
		if (ft_strcmp((char *)node->content, "$?") == 0)
		{
			aux = node->content;
			node->content = ft_itoa(shell->error_status);
			free(aux);
		}
		node = node->next;
	}
}

static void	ft_change_dquote(t_shell *shell, t_list **list)
{
	char	*aux;
	char	**splited;
	t_list	*node;

	node = *list;
	while (node)
	{
		if (ft_strstr((char *)node->content, "$?"))
		{
			splited = ft_split((char *)node->content, '$');
		}
		node = node->next;
	}
}
