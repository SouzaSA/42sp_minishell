/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_exit_num.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 09:06:49 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/05 16:02:07 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"
#include "ft_global_status.h"

static void	ft_change_symbol(t_list **list);
static char	*ft_change_dquote(char *str);
static void	ft_change_splited(char *num, char **splited);

void	ft_expand_exit_num(t_list *ast_stk)
{
	t_list		*node;
	t_cmd_blk	*blk;

	node = ast_stk;
	while (node)
	{
		if (node->content && ((t_ast *)node->content)->blk)
		{
			blk = ((t_ast *)node->content)->blk;
			ft_change_symbol(&blk->assign);
			ft_change_symbol(&blk->redir);
			ft_change_symbol(&blk->cmd);
		}
		node = node->next;
	}
}

static void	ft_change_symbol(t_list **list)
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
				node->content = ft_change_dquote((char *)node->content);
			else
				node->content = ft_itoa(g_exit_status);
			free(aux);
		}
		node = node->next;
	}
}

static char	*ft_change_dquote(char *str)
{
	char	*new;
	char	**splitted;

	splitted = ft_split(str, '$');
	ft_change_splited(ft_itoa(g_exit_status), splitted);
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
