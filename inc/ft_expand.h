/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:36:45 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/04 11:13:10 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXPAND_H
# define FT_EXPAND_H

# include <dirent.h>
# include <stdio.h>
# include "libft.h"

# define STAR '*'

enum	e_type
{
	T_DIR,
	T_FILE
};

typedef struct s_file
{
	char		*name;
	enum e_type	type;
}	t_file;

void	ft_test_expand_star(void);

t_list	*ft_expand_star(char *str);
t_list	*ft_get_splitted_path(char *path);
void	ft_clean_file_struct(t_file *fl);
void	ft_del_content(void *content);
void	ft_del_content_file_struct(void *content);
void	ft_add_expansion_to_list(t_list **list, t_list *dir, char *dir_to_open);
int		ft_match_star(char *pattern, char *text);
int		ft_is_dot_dir(char *dir);
char	*ft_pathcat(char *path_buffer, char *path);
int		ft_is_dir(unsigned char type);
void	ft_expand_list(t_list **list, t_list *dir, char *dir_to_open);

#endif
