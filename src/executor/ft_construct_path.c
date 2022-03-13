/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_construct_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 08:55:56 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/13 18:23:51 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

char	*ft_construct_path(char *cmd, t_list *env_lst)
{
	char	**path;
	char	*cmd_pathed;
	char	*key;

	path = NULL;
	key = ((t_dictionary *)env_lst->content)->key;
	while (env_lst && ft_strcmp(key, "PATH"))
	{
		env_lst = env_lst->next;
		if (env_lst)
			key = ((t_dictionary *)env_lst->content)->key;
	}
	if (env_lst && env_lst->content)
		path = ft_split(((t_dictionary *)env_lst->content)->value, ':');
	cmd_pathed = ft_get_cmd_path(cmd, path);
	ft_split_destroy(path);
	return (cmd_pathed);
}
