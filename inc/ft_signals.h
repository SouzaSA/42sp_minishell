/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:14:28 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/05 11:25:31 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGNALS_H
# define FT_SIGNALS_H

# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"

void	ft_handle_prompt_signals(void);
void	ft_handle_process_signals(void);
void	ft_handle_here_doc_signals(int pid);

#endif