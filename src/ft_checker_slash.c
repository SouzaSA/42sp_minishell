/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_slash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:29:06 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/10 08:51:08 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_checker_slash(char *str)
{
	int	has_slash;

	has_slash = 0;
	if (str && ft_strrchr(str, '/'))
		has_slash = 1;
	return (has_slash);
}
