/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match_star.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 09:58:30 by edpaulin          #+#    #+#             */
/*   Updated: 2022/02/18 17:45:08 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static int	ft_pattern_cmp(char *ptt, char *txt);

int	ft_match_star(char *pattern, char *text)
{
	while (*pattern && *text)
	{
		if (*pattern == '*')
		{
			while (*pattern && *pattern == '*')
				pattern++;
			if (!*pattern)
				return (1);
			text = ft_strchr(text, *pattern);
			if (!text)
				return (0);
		}
		if (ft_pattern_cmp(pattern, text))
		{
			if (*(pattern - 1) != '*' || !ft_match_star(pattern, text + 1))
				return (0);
		}
		pattern++;
		text++;
	}
	if (!*text && *pattern)
		return (0);
	return (1);
}

static int	ft_pattern_cmp(char *ptt, char *txt)
{
	while (*ptt && *txt && *ptt != '*' && *ptt == *txt)
	{
		ptt++;
		txt++;
	}
	if (*ptt == '*')
		return (0);
	return (*(unsigned char *)ptt - *(unsigned char *)txt);
}
