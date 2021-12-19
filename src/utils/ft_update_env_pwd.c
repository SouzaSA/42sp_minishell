/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_env_pwd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:41:05 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/19 16:58:36 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_update_env_pwd(t_shell *shell, char *new_pwd)
{
	char	*old_pwd;
	char	*aux;

	old_pwd = ft_get_env_value_by_key(shell, "OLDPWD")
	aux = ft_get_env_value_by_key(shell, "PWD")
	dic_item = (t_dictionary *)malloc(sizeof(t_dictionary));
	idx = (long)(ft_strchr(envp[i], '=') - &envp[i][0]);
	dic_item->key = ft_strdup("OLDPWD");
	dic_item->value = ;
	ft_export(shell, ft_lstnew(dic_item));
}
