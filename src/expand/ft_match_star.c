/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match_star.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 09:58:30 by edpaulin          #+#    #+#             */
/*   Updated: 2022/02/11 09:58:55 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

int	ft_match_star(char *pattern, char *text)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (pattern[i])
	{
		while (pattern[i] == STAR && pattern[i])
			i++;
		if (!pattern[i])
			break ;
		if (i == 0 && pattern[i] != text[j])
			return (0);
		while (text[j] != pattern[i] && text[j])
			j++;
		if (!text[j])
			return (0);
		i++;
		j++;
	}
	if (!pattern[i] && pattern[i - 1] != STAR && text[j])
		return (0);
	return (1);
}
