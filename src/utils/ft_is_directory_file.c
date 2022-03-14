/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_directory_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:29:35 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/13 21:10:04 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int	ft_is_directory_file(const char *file)
{
	struct stat	file_stat;

	file_stat.st_mode = 0;
	stat(file, &file_stat);
	return (S_ISDIR(file_stat.st_mode));
}
