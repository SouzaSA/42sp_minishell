/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_env_pwd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:41:05 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/08 20:08:53 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_update_env_pwds(t_shell *shell, char *new_pwd)
{
	char	*tmp_pwd;
	char	*tmp_old_pwd;
	t_list	*node_old_pwd;
	t_list	*node_pwd;

	node_old_pwd = ft_get_env_node_by_key(shell, "OLDPWD");
	node_pwd = ft_get_env_node_by_key(shell, "PWD");
	tmp_pwd = ((t_dictionary *)node_pwd->content)->value;
	tmp_old_pwd = ((t_dictionary *)node_old_pwd->content)->value;
	((t_dictionary *)node_old_pwd->content)->value = tmp_pwd;
	((t_dictionary *)node_pwd->content)->value = new_pwd;
	free(tmp_old_pwd);
	return (0);
}
