/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isidentifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:38:43 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/25 15:39:05 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int	ft_isidentifier(char *str)
{
	int	i;
	int	rtn;

	if (!str)
		return (0);
	i = 1;
	rtn = 1;
	if (!ft_isalpha(str[0]) && str[0] != '_')
		rtn = 0;
	while (rtn && str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			rtn = 0;
		i++;
	}
	return (rtn);
}
