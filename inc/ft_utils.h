/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:32:33 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/03 18:31:00 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "ft_ast_struct.h"
# include "ft_grammar_symbols.h"
# include "libft.h"
# include "ft_shell_struct.h"

void	ft_destroy_ast_stk(t_list **ast_stk);
void	ft_destroy_ast(t_ast **ast);
void	ft_destroy_command(t_cmd_blk **blk);
void	ft_destroy_dictionary_element(void *dic_item);
void	ft_destroy_dictionary_list(t_list **dic_lst);
void	ft_destroy_shell(t_shell *shell);
t_list	*ft_get_env_node_by_key(t_shell *shell, char *key);
char	*ft_get_env_value_by_key(t_shell *shell, char *key);
void	ft_init_minishell(t_shell *shell, char **envp);
int		ft_isidentifier(char *str);
int		ft_update_env_pwds(t_shell *shell, char *new_pwd);
#endif
