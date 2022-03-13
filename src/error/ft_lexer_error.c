/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:55:05 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/12 21:00:03 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

int	ft_lexer_error(void)
{
	g_exit_status = 2;
	ft_put_msg_error("lexer: unbalanced quotes", FLAG_ERROR_OWN);
	return (1);
}
