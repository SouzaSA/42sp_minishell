/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 10:21:23 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/23 21:38:44 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_mod(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*dst;

	i = 0;
	s1_len = ft_strlen_set(s1, "\0");
	s2_len = ft_strlen_set(s2, "\0");
	dst = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (dst)
	{
		while (i < s1_len || i < s2_len)
		{
			if (i < s1_len)
				dst[i] = s1[i];
			if (i < s2_len)
				dst[i + s1_len] = s2[i];
			i++;
		}
		dst[s1_len + s2_len] = '\0';
	}
	return (dst);
}

size_t	ft_strlen_set(const char *s, const char *set)
{
	size_t	i;
	size_t	j;
	int		found;

	i = 0;
	if (s)
	{
		found = 0;
		while (s[i] != '\0' && !found)
		{
			j = 0;
			while (set[j] != '\0')
			{
				if (s[i] == set[j])
					found = 1;
				j++;
			}
			i++;
		}
		if (s[i] == '\n' && s[i - 1] != '\n')
			i++;
	}
	return (i);
}

void	ft_push_line(int fd, char **str_buff)
{
	ssize_t	gotten;
	char	*tmp;
	char	*buff;

	gotten = 0;
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buff)
		gotten = read(fd, buff, BUFFER_SIZE);
	if (gotten > 0)
	{
		buff[gotten] = '\0';
		while (gotten > 0 && !ft_strchr(buff, '\n'))
		{
			tmp = *str_buff;
			*str_buff = ft_strjoin_mod(*str_buff, buff);
			if (tmp)
				free(tmp);
			gotten = read(fd, buff, BUFFER_SIZE);
			buff[gotten] = '\0';
		}
		tmp = *str_buff;
		*str_buff = ft_strjoin_mod(*str_buff, buff);
		free(tmp);
	}
	free(buff);
}

char	*ft_pop_line(char **str_buff)
{
	size_t	i;
	size_t	line_len;
	char	*str;
	char	*tmp;

	i = 0;
	str = NULL;
	if (*str_buff && (*str_buff)[0] != '\0')
	{
		line_len = ft_strlen_set(*str_buff, "\n");
		str = (char *)malloc((line_len + 1) * sizeof(char));
		while (i < line_len)
		{
			str[i] = (*str_buff)[i];
			i++;
		}
		str[line_len] = '\0';
		tmp = *str_buff;
		*str_buff = ft_strjoin_mod(*str_buff + line_len, "");
		free(tmp);
	}
	return (str);
}
