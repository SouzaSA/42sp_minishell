/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_tild.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 10:47:08 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/06 14:46:41 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static void	ft_change_tild(t_shell *shell, t_list *list);
static char	*ft_get_home(t_shell *shell);

int	ft_expand_tild(t_shell *shell, t_list *ast_stk)
{
	t_list		*node;
	t_cmd_blk	*blk;

	node = ast_stk;
	while (node)
	{
		if (node->content && ((t_ast *)node->content)->blk)
		{
			blk = ((t_ast *)node->content)->blk;
			ft_change_tild(shell, blk->assign);
			ft_change_tild(shell, blk->redir);
			ft_change_tild(shell, blk->cmd);
		}
		node = node->next;
	}
	return (0);
}

static void	ft_change_tild(t_shell *shell, t_list *list)
{
	char	*aux;
	char	*str;
	char	*home;
	t_list	*node;

	node = list;
	home = ft_get_home(shell);
	while (node)
	{
		str = (char *)node->content;
		if (str && str[0] == '~' && (str[1] == ' ' || str[1] == '/' || !str[1]))
		{
			aux = node->content;
			if (aux && ft_strlen(aux) == 1)
				node->content = ft_strdup(home);
			else
				node->content = ft_strjoin(home, &aux[1]);
			free(aux);
		}
		node = node->next;
	}
	free(home);
}

static char	*ft_get_home(t_shell *shell)
{
	char	*value;

	value = ft_get_env_value_by_key(shell, "HOME");
	if (value)
		return (ft_strdup(value));
	else
		return (ft_strdup(""));
}
