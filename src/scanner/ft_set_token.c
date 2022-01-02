/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:51:29 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/25 13:24:20 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scanner.h"

t_token	*ft_set_token(t_token *tok, t_source *src, char *str)
{
	char	*nstr;

	ft_memset(tok, 0, sizeof(t_token));
	tok->text_len = strlen(str);
	nstr = (char *)malloc(tok->text_len + 1);
	if (!nstr)
	{
		ft_put_msg_error("scanner: failed to alloc buffer", FLAG_ERROR_P);
		tok->end_flag = 1;
		return (tok);
	}
	ft_strcpy(nstr, str);
	tok->text = nstr;
	tok->src = src;
	return (tok);
}
