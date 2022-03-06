/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:14:28 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/06 15:55:46 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGNALS_H
# define FT_SIGNALS_H

# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# include "ft_global_status.h"

void	ft_handle_prompt_signals(void);
void	ft_att_status(int signal);
void	ft_handle_child_process_signals(void);
void	ft_handle_parent_process_signals(void);

#endif