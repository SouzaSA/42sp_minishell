/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_construct_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 08:55:56 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/23 11:47:43 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

char	**ft_construct_path(char **cmd, t_list *env_lst)
{
	char	**path;
	char	*key;

	path = NULL;
	key = ((t_dictionary *)env_lst->content)->key;
	while (env_lst && ft_strcmp(key, "PATH"))
	{
		env_lst = env_lst->next;
		key = ((t_dictionary *)env_lst->content)->key;
	}
	if (env_lst && env_lst->content)
		path = ft_split(((t_dictionary *)env_lst->content)->value, ':');
	cmd[0] = ft_get_cmd_path(cmd[0], path);
	ft_split_destroy(path);
	return (cmd);
}
