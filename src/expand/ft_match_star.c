/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match_star.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:24:11 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/02 18:24:47 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static int	ft_pattern_cmp(char *pattern, char *text);

int	ft_match_star(char *pattern, char *text)
{
	const char	*p_bkp = pattern;

	if (!ft_strcmp(pattern, text))
		return (1);
	if (ft_is_dot_dir(text))
		return (0);
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
			// if (p_bkp == pattern || *(pattern - 1) != '*')
			if (p_bkp == pattern || *(pattern - 1) != '*' || !ft_match_star(pattern, text + 1))
				return (0);
			text = ft_strchr(text, *pattern);
			if (!text)
				return (0);
			continue ;
		}
		pattern++;
		text++;
	}
	if (!*text && *pattern)
		return (0);
	return (1);
}

static int	ft_pattern_cmp(char *pattern, char *text)
{
	while (*pattern && *text && *pattern != '*' && *pattern == *text)
	{
		pattern++;
		text++;
	}
	if (*pattern == '*')
		return (0);
	return (*(unsigned char *)pattern - *(unsigned char *)text);
}
