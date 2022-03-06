/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_struct.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:22:47 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/05 17:04:19 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHELL_STRUCT_H
# define FT_SHELL_STRUCT_H

# include "libft.h"
# include "ft_grammar_symbols.h"

typedef struct s_dictionary
{
	char	*key;
	char	*value;
}	t_dictionary;

typedef struct s_shell
{
	t_list	*env_list;
	t_list	*vars;
	int		lineno;
	char	*line;
	void	(***transition_table)(t_list **, enum e_symbol);
}	t_shell;

#endif