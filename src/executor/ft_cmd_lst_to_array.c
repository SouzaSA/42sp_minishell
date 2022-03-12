/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_lst_to_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:48:53 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/11 21:27:33 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

static char	**ft_create_array(t_list *cmd);

char	**ft_cmd_lst_to_array(t_shell *shell, t_list **cmd)
{
	char	**cmd_array;
	char	*pathed;
	char	*aux;

	pathed = NULL;
	cmd_array = NULL;
	if (cmd && (char *)(*cmd)->content)
		pathed = ft_construct_path((char *)(*cmd)->content, shell->env_list);
	if (pathed)
	{
		aux = (char *)(*cmd)->content;
		(*cmd)->content = pathed;
		free(aux);
		ft_expand_star(cmd);
		if (ft_lstsize(*cmd) > 1L << 12)
			ft_expand_error((char *)(*cmd)->content, FLAG_ERROR_CMD);
		else
			cmd_array = ft_create_array(*cmd);
	}
	return (cmd_array);
}

static char	**ft_create_array(t_list *cmd)
{
	int		i;
	t_list	*node;
	char	*aux;
	char	**cmd_array;

	i = 0;
	cmd_array = NULL;
	if (cmd)
	{
		cmd_array = (char **)malloc((ft_lstsize(cmd) + 1) * sizeof(char *));
		node = cmd;
		while (cmd_array && node)
		{
			aux = (char *)node->content;
			node->content = ft_str_remove_quotes(aux);
			free(aux);
			cmd_array[i] = (char *)node->content;
			node = node->next;
			i++;
		}
		cmd_array[i] = NULL;
	}
	return (cmd_array);
}
