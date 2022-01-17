/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:02:24 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/17 15:24:28 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "ft_colors.h"
# include "ft_error.h"
# include "ft_executor.h"
# include "libft.h"
# include "ft_parser.h"
# include "ft_scanner.h"

typedef struct s_dictionary
{
	char	*key;
	char	*value;
}	t_dictionary;

typedef struct s_shell
{
	t_list	*env_list;
	int		error_status;
}	t_shell;

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

void	ft_destroy_dictionary_element(void *dic_item);
void	ft_destroy_vars(t_shell *shell);
t_list	*ft_get_env_node_by_key(t_shell *shell, char *key);
char	*ft_get_env_value_by_key(t_shell *shell, char *key);
void	ft_init_minishell(t_shell *shell, char **envp);
int		ft_update_env_pwds(t_shell *shell, char *new_pwd);

void	ft_handle_sigint(int signal);
void	ft_handle_sigquit(int signal);
#endif
