/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:02:24 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/20 09:16:17 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# include "ft_colors.h"

# define EXIT_SHELL_SUCCESS 0
# define EXIT_SHELL_ERROR_GENERIC 1
# define EXIT_SHELL_ERROR_MISSUSE_BUITIN 2
# define EXIT_SHELL_ERROR_CANNOT_EXECUTE 126
# define EXIT_SHELL_ERROR_CMD_NOT_FOUND 127
# define EXIT_SHELL_ERROR_INVALID_ARG_TO_EXIT 128
# define EXIT_SHELL_ERROR_SIGNAL_N 128

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

int		ft_env(t_shell *shell);
void	 ft_export(t_shell *shell, char *key, char *value);

void	ft_destroy_vars(t_shell *shell);
char	*ft_get_env_value_by_key(t_shell *shell, char *key);
void	ft_init_minishell(t_shell *shell, char **envp);
int		ft_put_msg_error(t_shell *shell, char *msg, int error_flag);
void	ft_destroy_dictionary_element(void *dic_item);
#endif
