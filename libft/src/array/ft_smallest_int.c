/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smallest_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:38:43 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/13 11:13:56 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_smallest_int_idx(int *array, size_t size)
{
	size_t	i;
	int		min;

	i = 1;
	min = 0;
	if (array && size > 0)
	{
		while (i < size)
		{
			if (array[min] > array[i])
				min = i;
			i++;
		}
	}
	return (min);
}
