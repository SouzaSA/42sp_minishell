/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:36:45 by edpaulin          #+#    #+#             */
/*   Updated: 2022/02/11 16:28:10 by edpaulin         ###   ########.fr       */
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

#endif