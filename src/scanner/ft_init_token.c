/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 10:48:42 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/15 14:29:48 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scanner.h"

t_token	*ft_init_token(void)
{
	t_token	*tok;

	tok = (t_token *)malloc(sizeof(t_token));
	if (!tok)
	{
		ft_put_msg_error("scanner: failed to alloc token", FLAG_ERROR_P);
		return (NULL);
	}
	tok->tok_type = TS_UNKNOWN;
	tok->src = NULL;
	tok->text_len = 0;
	tok->text = NULL;
	return (tok);
}
