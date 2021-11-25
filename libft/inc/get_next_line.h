/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 16:42:15 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/24 16:41:12 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_fd_list
{
	int					fd;
	char				*str_buff;
	struct s_fd_list	*next;
}	t_fd_list;

char		*get_next_line(int fd);
t_fd_list	*ft_new_fd(int fd);
t_fd_list	*ft_get_fd(t_fd_list **fd_list, int fd);
void		ft_del_list(t_fd_list **fd_list, t_fd_list *node_fd);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin_mod(char const *s1, char const *s2);
size_t		ft_strlen_set(const char *s, const char *set);
void		ft_push_line(int fd, char **str_buff);
char		*ft_pop_line(char **str_buff);
#endif
