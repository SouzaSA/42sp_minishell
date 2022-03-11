/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match_star.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:24:11 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/04 18:29:41 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"
#include <string.h>

static int		ft_recursive_match(char *pattern, char *text);
static size_t	ft_block_size(char *block);

int	ft_match_star(char *pattern, char *text)
{
	if (!pattern || !text)
		return (0);
	if (ft_strcmp(pattern, text) == 0)
		return (1);
	if (ft_is_dot_dir(text))
		return (0);
	return (ft_recursive_match(pattern, text));
}

static int	ft_recursive_match(char *pattern, char *text)
{
	char	*block;

	if (*pattern == '*')
	{
		while (*pattern == '*')
			pattern++;
		if (!*pattern)
			return (1);
		block = ft_substr(pattern, 0, ft_block_size(pattern));
		text = ft_strstr(text, block);
		free(block);
		if (!text)
			return (0);
	}
	while (*pattern && *text && *pattern == *text)
	{
		pattern++;
		text++;
	}
	if ((!*pattern && !*text) || (*pattern == '*' && *(pattern + 1) == '\0'))
		return (1);
	if (*pattern == '*')
		return (ft_recursive_match(pattern, text));
	return (0);
}

static size_t	ft_block_size(char *block)
{
	size_t	size;

	size = 0;
	while (block[size] != '*' && block[size] != '\0')
		size++;
	return (size);
}
