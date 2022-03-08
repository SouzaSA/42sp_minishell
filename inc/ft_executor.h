/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 20:54:08 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/08 15:34:57 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXECUTOR_H
# define FT_EXECUTOR_H

# include <fcntl.h>
# include "ft_builtins.h"
# include "ft_parser.h"
# include "ft_utils.h"
# include "ft_command_struct.h"
# include "ft_expand.h"
# include "ft_global_status.h"
# include "ft_signals.h"

int		ft_and_or_run(t_cmd_data *data, enum e_ast_type type);
int		ft_builtin_run(t_shell *shell, t_cmd_data *data, t_ast *ast);
int		ft_checker_slash(char *str);
int		ft_assignments(t_shell *shell, t_list *assign);
void	ft_cmd_data_init(t_cmd_data *data, t_list **cmd_stk);
int		ft_redirections(t_shell *shell, t_cmd_data *data);
int		ft_cmd_run(t_shell *shell, t_cmd_data *data, t_ast *ast);
char	**ft_construct_envp(t_list *env_lst);
char	**ft_construct_path(char **cmd, t_list *env_lst);
int		ft_executor(t_shell *shell, char *line);
char	*ft_get_cmd_path(char *command, char **path_list);
int		ft_here_doc(t_shell *shell, char *limiter, t_cmd_data *data);
int		ft_pipe_run(t_cmd_data *data);
void	ft_pipe_worker(t_cmd_data *data);
void	ft_single_buitin(t_shell *shell, t_list **cmd_stk, t_cmd_data *data);
#endif
