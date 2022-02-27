/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 20:54:08 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/26 18:20:55 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXECUTOR_H
# define FT_EXECUTOR_H

# include <fcntl.h>
# include "ft_builtins.h"
# include "ft_parser.h"
# include "ft_utils.h"

typedef struct s_cmd_data
{
	char	**cmd;
	int		fd_in;
	int		fd_out;
	int		builtin_flag;
	int		pipe_flag;
	int		pipe_fd[2];
	int		pid;
	t_list	**cmd_stk;
}	t_cmd_data;

int		ft_and_or_run(t_cmd_data *cmd_data, enum e_ast_type type);
int		ft_builtin_run(t_shell *shell, t_cmd_data *cmd_data, t_ast *ast);
int		ft_checker_slash(char *str);
int		ft_assignments(t_shell *shell, t_list *assign);
int		ft_redirections(t_list *redir, int *fd_in, int *fd_out);
int		ft_cmd_run(t_shell *shell, t_cmd_data *cmd_data, t_ast *ast);
char	**ft_construct_envp(t_list *env_lst);
char	**ft_construct_path(char **cmd, t_list *env_lst);
int		ft_executor(t_shell *shell, char *line);
char	*ft_get_cmd_path(char *command, char **path_list);
int		ft_here_doc(char *limiter);
int		ft_pipe_run(t_cmd_data *cmd_data);
#endif
