/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_slash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:29:06 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/30 15:29:26 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_checker_slash(char *str)
{
	int	has_slash;

	has_slash = 0;
	if (ft_strncmp(str, "/", 1) == 0 || ft_strncmp(str, "./", 2) == 0 \
		|| ft_strncmp(str, "../", 3) == 0)
		has_slash = 1;
	return (has_slash);
}
