/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:07:06 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/02 16:22:07 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILTINS_H
# define FT_BUILTINS_H

# include <sys/stat.h>
# include "ft_ast_struct.h"
# include "ft_shell_struct.h"
# include "ft_utils.h"
# include "ft_error.h"

int		ft_builin_parser(t_shell *shell, t_command *command);
int		ft_cd(t_shell *shell, t_list *cmd);
int		ft_echo(t_list *cmds);
int		ft_env(t_shell *shell);
void	ft_env_search_and_add(t_shell *shell, t_list *new_node);
int		ft_exit(t_shell *shell, t_list *cmds);
int		ft_export_exec(t_shell *shell, t_list *exp_var);
int		ft_export(t_shell *shell, t_list *assigns);
int		ft_isbuiltin(char *cmd);
int		ft_pwd(void);
int		ft_unset(t_shell *shell, t_list *cmds);

#endif
