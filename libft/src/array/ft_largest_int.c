/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_largest_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:38:39 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/13 11:13:59 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_largest_int_idx(int *array, size_t size)
{
	size_t	i;
	int		max;

	i = 1;
	max = 0;
	if (array && size > 0)
	{
		while (i < size)
		{
			if (array[max] < array[i])
				max = i;
			i++;
		}
	}
	return (max);
}
