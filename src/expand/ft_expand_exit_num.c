/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_exit_num.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 09:06:49 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/04 22:18:11 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static void	ft_change_symbol(t_shell *shell, t_list **list);
static char	*ft_change_dquote(t_shell *shell, char *str);
static void	ft_change_splited(char *num, char **splited);

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
			if (((char *)node->content)[0] == '\"')
				node->content = ft_change_dquote(shell, (char *)node->content);
			else
				node->content = ft_itoa(shell->status);
			free(aux);
		}
		node = node->next;
	}
}

static char	*ft_change_dquote(t_shell *shell, char *str)
{
	char	*new;
	char	**splitted;

	splitted = ft_split(str, '$');
	ft_change_splited(ft_itoa(shell->status), splitted);
	new = ft_split_join(splitted);
	ft_split_destroy(splitted);
	return (new);
}

static void	ft_change_splited(char *num, char **splited)
{
	int		i;
	char	*aux;

	i = 0;
	while (splited[i])
	{
		if (splited[i][0] == '?')
		{
			aux = splited[i];
			splited[i] = ft_strjoin(num, &splited[i][1]);
			free (aux);
		}
		i++;
	}
}
