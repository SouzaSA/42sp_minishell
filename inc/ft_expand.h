/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:36:45 by edpaulin          #+#    #+#             */
/*   Updated: 2022/02/18 13:39:45 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXPAND_H
# define FT_EXPAND_H

# include <dirent.h>
# include <stdio.h>
# include "libft.h"

# define STAR '*'

t_list	*ft_expand_star(char *str);
void	ft_del_list_content(void *content);
int		ft_match_star(char *pattern, char *text);
void	ft_test_expand_star(void);
void	ft_get_expanded_list(t_list **list, t_list *dir, char *dir_to_open);
void	ft_get_file_list(t_list **list, char *pattern, DIR *folder, char *path);
int		ft_is_dot_dir(char *dir);

t_list	*ft_split_path(char *path);
char	*ft_pathcat(char *path, char *file);

int		ft_is_dir(unsigned char type);

#endif