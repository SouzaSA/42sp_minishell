/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match_star.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:24:11 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/04 09:13:08 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static t_star	*ft_create_source(char *str);
static int		ft_clean_and_return (t_star *s1, t_star *s2, int ret);
static void		ft_clean_source(t_star *src);
static int		ft_get_next_char(t_star *src);
// static int		ft_peek_next_char(t_star *src);
// static void		ft_skip_star(t_star *src);
// static int		ft_get_previous_char(t_star *src);
static int		ft_peek_previous_char(t_star *src);

#define true 1
#define false 0
#define end_of_source 3

int	ft_match_star(char *pattern, char *text)
{
	t_star	*p;
	t_star	*t;
	char		pc;
	char		tc;

	// printf("pattern: %s\n", pattern);
	// printf("text: %s\n", text);
	if (!pattern || !text)
		return (0);
	if (!ft_strcmp(pattern, text))
		return (1);
	if (ft_is_dot_dir(text))
		return (0);
	p = ft_create_source(pattern);
	if (!p)
		return (0);
	t = ft_create_source(text);
	if (!t)
	{
		ft_clean_source(p);
		return (0);
	}
	pc = ft_get_next_char(p);
	tc = ft_get_next_char(t);
	while (pc != end_of_source && tc != end_of_source)
	{
		// printf("pc: %c\n", pc);
		// printf("tc: %c\n", tc);
		if (pc == '*')
		{
			while (pc == '*')
				pc = ft_get_next_char(p);
			if (pc == end_of_source)
				return (ft_clean_and_return(p, t, true));
			while (tc != pc && tc != end_of_source)
				tc = ft_get_next_char(t);
			if (tc == end_of_source)
				return (ft_clean_and_return(p, t, false));
		}
		if (pc == tc)
		{
			pc = ft_get_next_char(p);
			tc = ft_get_next_char(t);
		}
		else
		{
			// the problem is here!!!
			tc = ft_get_next_char(t);
			while (tc != pc && tc != end_of_source)
				tc = ft_get_next_char(t);
			if (tc == end_of_source)
				return (ft_clean_and_return(p, t, false));
		}
	}
	if ((t->i < t->len && ft_peek_previous_char(p) != '*') || p->i < p->len)
		return (ft_clean_and_return(p, t, false));
	return (ft_clean_and_return(p, t, true));
}

static int	ft_clean_and_return (t_star *s1, t_star *s2, int ret)
{
	ft_clean_source(s1);
	ft_clean_source(s2);
	// printf("------------------------------------\n");
	return (ret);
}

static t_star	*ft_create_source(char *str)
{
	t_star	*src;

	src = malloc(sizeof(t_star));
	if (!src)
		return (NULL);
	src->str = ft_strdup(str);
	if (!src->str)
	{
		free(src);
		return (NULL);
	}
	src->len = ft_strlen(src->str);
	src->i = -1;
	return (src);
}

static void	ft_clean_source(t_star *src)
{
	if (!src)
		return ;
	if (src->str)
		free(src->str);
	free(src);
}

static int	ft_get_next_char(t_star *src)
{
	if (src->i >= src->len)
		return (end_of_source);
	src->i++;
	return (src->str[src->i]);
}

// static int	ft_peek_next_char(t_source *src)
// {
// 	if ((src->i + 1) >= src->len)
// 		return (end_of_source);
// 	return (src->str[src->i + 1]);
// }

// static void	ft_skip_star(t_source *src)
// {
// 	while (ft_peek_next_char(src) == '*')
// 		src->i++;
// }

// static int	ft_get_previous_char(t_source *src)
// {
// 	if ((src->i - 1) < 0)
// 		return (end_of_source);
// 	src->i--;
// 	return (src->str[src->i]);
// }

static int	ft_peek_previous_char(t_star *src)
{
	if ((src->i - 1) < 0)
		return (end_of_source);
	return (src->str[src->i - 1]);
}