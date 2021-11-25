/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 16:36:56 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/23 21:15:30 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_fd_list	*desc_list = NULL;
	t_fd_list			*fd_node;
	char				*str;
	char				*str_tmp;

	str = NULL;
	fd_node = NULL;
	if (fd >= 0 && read(fd, str, 0) == 0 && BUFFER_SIZE > 0)
	{
		fd_node = ft_get_fd(&desc_list, fd);
		if (fd_node)
		{
			str_tmp = fd_node->str_buff;
			if (str_tmp && !str_tmp[0] && ft_strchr(str_tmp, '\n'))
				str = ft_pop_line(&(fd_node->str_buff));
			else
			{
				ft_push_line(fd, &(fd_node->str_buff));
				str = ft_pop_line(&(fd_node->str_buff));
			}
		}
		if (!str || (fd_node && fd_node->str_buff && !((fd_node->str_buff)[0])))
			ft_del_list(&desc_list, fd_node);
	}
	return (str);
}

t_fd_list	*ft_new_fd(int fd)
{
	t_fd_list	*new_node;

	new_node = (t_fd_list *)malloc(sizeof(t_fd_list));
	if (new_node)
	{
		new_node->fd = fd;
		new_node->str_buff = NULL;
		new_node->next = NULL;
	}
	return (new_node);
}

t_fd_list	*ft_get_fd(t_fd_list **fd_list, int fd)
{
	t_fd_list	*list;

	if (!(*fd_list))
		*fd_list = ft_new_fd(fd);
	list = *fd_list;
	while (list->fd != fd && list->next)
		list = list->next;
	if (list->fd != fd)
	{
		list->next = ft_new_fd(fd);
		list = list->next;
	}
	return (list);
}

void	ft_del_list(t_fd_list **fd_list, t_fd_list *node_fd)
{
	int			is_clean;
	t_fd_list	*list;

	is_clean = 1;
	if (*fd_list)
	{
		if (node_fd->str_buff)
			free(node_fd->str_buff);
		node_fd->str_buff = NULL;
		list = *fd_list;
		while (list)
		{
			if (list->str_buff)
				is_clean = 0;
			list = list->next;
		}
		list = *fd_list;
		while (is_clean && list)
		{
			list = (*fd_list)->next;
			if (*fd_list)
				free(*fd_list);
			*fd_list = list;
		}
	}
}
