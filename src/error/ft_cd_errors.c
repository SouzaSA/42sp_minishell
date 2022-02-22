/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:09:09 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/21 10:29:34 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

int	ft_cd_error(t_shell *shell, char *msg, int error_flag)
{
	char	*cd_err_msg;

	cd_err_msg = ft_strjoin("cd: ", msg);
	ft_put_msg_error(cd_err_msg, error_flag);
	free(cd_err_msg);
	shell->error_status = 1;
	return (1);
}
