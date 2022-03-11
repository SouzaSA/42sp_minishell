/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:51:36 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/15 10:54:20 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scanner.h"

void	ft_del_token(void *tok)
{
	if (((t_token *)tok)->text)
		free(((t_token *)tok)->text);
	free(tok);
}
