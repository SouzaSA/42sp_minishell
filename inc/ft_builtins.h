/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:07:06 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/23 16:22:10 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILTIN_H
# define FT_BUILTIN_H

# include "ft_shell_struct.h"
# include "ft_ast_struct.h"

int	ft_builin_parser(t_shell *shell, t_command *command);
int	ft_cd(t_shell *shell, t_list *cmd);
int	ft_echo(t_list *cmds);
int	ft_env(t_shell *shell);
int	ft_exit(t_shell *shell, t_list *cmds);
int	ft_export(t_shell *shell, t_list *assigns);
int	ft_isbuiltin(char *cmd);
int	ft_pwd();
int	ft_unset(t_shell *shell, t_list *cmds);

#endif