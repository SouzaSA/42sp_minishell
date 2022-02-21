/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:02:24 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/20 09:09:48 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <signal.h>
# include "ft_colors.h"
# include "ft_error.h"
# include "ft_executor.h"
# include "ft_parser.h"
# include "ft_scanner.h"
# include "ft_expand.h"
# include "ft_utils.h"

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

int		ft_cd(t_shell *shell, char **cmd);
int		ft_env(t_shell *shell);
void	ft_export(t_shell *shell, char *key, char *value);
int		ft_pwd();//t_shell *shell);
void	ft_unset(t_shell *shell, char *key);



void	ft_handle_sigint(int signal);
void	ft_handle_sigquit(int signal);
#endif
