/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:14:29 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/05 15:05:05 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

int	ft_heredoc_error(char *eof_name, int lineno)
{
	char	*num;

	num = ft_itoa(lineno);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("warning: here-document at line ", 2);
	ft_putstr_fd(num, 2);
	ft_putstr_fd(" delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(eof_name, 2);
	ft_putendl_fd("')", 2);
	free(num);
	return (1);
}
