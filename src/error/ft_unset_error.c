/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:39:12 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/05 11:30:44 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

int	ft_unset_error(char *msg, int error_flag)
{
	char	*error_msg;
	char	*aux;

	error_msg = ft_strjoin("unset: `", msg);
	aux = error_msg;
	error_msg = ft_strjoin(error_msg, "': not a valid identifier");
	ft_put_msg_error(error_msg, error_flag);
	free(aux);
	free(error_msg);
	return (1);
}
