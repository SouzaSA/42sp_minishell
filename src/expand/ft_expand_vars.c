/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_vars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:54:08 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/11 10:49:31 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static char	*ft_change_str(t_shell *shell, char *str);
static void	ft_change_splited(t_shell *shell, char **splited);
static void	ft_change_var(t_shell *shell, t_list **list);
static char	*ft_get_var(t_shell *shell, char *key);

int	ft_expand_vars(t_shell *shell, t_list *ast_stk)
{
	t_list		*node;
	t_cmd_blk	*blk;

	node = ast_stk;
	while (node)
	{
		if (node->content && ((t_ast *)node->content)->blk)
		{
			blk = ((t_ast *)node->content)->blk;
			ft_change_var(shell, &blk->assign);
			ft_change_var(shell, &blk->redir);
			ft_change_var(shell, &blk->cmd);
		}
		node = node->next;
	}
	return (0);
}

static void	ft_change_var(t_shell *shell, t_list **list)
{
	char	*aux;
	char	*val;
	t_list	*node;

	node = *list;
	while (node)
	{
		aux = NULL;
		val = NULL;
		if (node->content)
			aux = (char *)node->content;
		if (aux)
			val = ft_strchr(aux, '=');
		if ((aux && aux[0] != '\'' && ft_strchr(aux, '$')) \
			&& (!val || (val && val[1] != '\'')))
		{
			node->content = ft_change_str(shell, aux);
			free(aux);
		}
		node = node->next;
	}
}

static char	*ft_change_str(t_shell *shell, char *str)
{
	char	*new;
	char	**splitted;

	splitted = ft_split(str, '$');
	if (str[0] == '$')
		ft_change_splited(shell, splitted);
	else
		ft_change_splited(shell, &splitted[1]);
	new = ft_split_join(splitted);
	ft_split_destroy(splitted);
	return (new);
}

static void	ft_change_splited(t_shell *shell, char **splited)
{
	int		i;
	char	*posfix;
	char	*key;
	char	*value;
	char	*aux;

	i = 0;
	while (splited[i])
	{
		posfix = splited[i];
		if (*posfix == '_' || ft_isalpha(*posfix))
		{
			while (*posfix == '_' || ft_isalnum(*posfix))
				posfix++;
		}
		key = ft_substr(splited[i], 0, posfix - splited[i]);
		value = ft_get_var(shell, key);
		aux = splited[i];
		if (value && posfix)
			splited[i] = ft_strjoin(value, posfix);
		free(value);
		free(aux);
		free(key);
		i++;
	}
}

static char	*ft_get_var(t_shell *shell, char *key)
{
	t_list	*node;

	if (*key == '\0')
		return (ft_strdup("$"));
	node = ft_get_local_var_node_by_key(shell, key);
	if (!node)
		node = ft_get_env_node_by_key(shell, key);
	if (node)
		return (ft_strdup(((t_dictionary *)node->content)->value));
	else
		return (ft_strdup(""));
}
