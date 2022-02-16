/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_construct_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 08:55:56 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/15 09:44:55 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

char	**ft_construct_path(t_list *cmd_list, t_list *env_lst)
{
	int		i;
	char	*aux;
	char	**cmd;
	char	**path;

	i = 0;
	cmd = (char **)malloc(ft_lstsize(cmd_list) * (sizeof(char *) + 1));
	while (cmd_list)
	{
		aux = cmd_list;
		cmd[i] = (char *)cmd_list->content;
		i++;
		cmd_list = cmd_list->next;
		free(aux);
	}
	cmd[i] = NULL;
	while (env_lst && ft_strcmp(((t_dictionary *)env_lst->content)->key, "PATH"))
		env_lst = env_lst->next;
	path = ft_split(((t_dictionary *)env_lst->content)->value, ':');
	cmd[0] = ft_get_cmd_path(cmd[0], path);
	ft_split_destroy(path);
	return (cmd);
}
