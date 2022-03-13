/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:02:24 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/13 19:42:37 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_builtins.h"
# include "ft_error.h"
# include "ft_executor.h"
# include "ft_parser.h"
# include "ft_scanner.h"
# include "ft_expand.h"
# include "ft_utils.h"
# include "libft.h"
# include "ft_global_status.h"

# define PROMPT_SIZE 4096
# define PROMPT_DOLLAR "\001\033[0;32m$\e[0;39m\002 "
# define CYAN "\001\033[0;36m\002"
# define END_COLOR "\001\e[0;39m\002"

typedef struct s_cmd_tbl
{
	int		infile;
	int		outfile;
	long	pid;
	char	**full_cmd;
	char	*full_path;
}	t_cmd_tbl;

char	**ft_get_path(char **envp);
int		ft_minishell(char **envp);
char	*ft_get_prompt(void);

#endif
