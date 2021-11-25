/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 11:01:34 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/14 16:03:57 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_partition(int *array, int first_idx, int last_idx);
static void	ft_swap(int *a, int *b);

void	ft_quick_sort(int *array, int first_idx, int last_idx)
{
	int	pivot;

	if (first_idx < last_idx)
	{
		pivot = ft_partition(array, first_idx, last_idx);
		ft_quick_sort(array, first_idx, pivot - 1);
		ft_quick_sort(array, pivot + 1, last_idx);
	}
}

static int	ft_partition(int *array, int first_idx, int last_idx)
{
	int	i;
	int	j;
	int	pivot;

	i = first_idx;
	j = first_idx;
	pivot = array[last_idx];
	while (i < last_idx)
	{
		if (array[i] < pivot)
		{
			ft_swap(&array[j], &array[i]);
			j++;
		}
		i++;
	}
	ft_swap(&array[j], &array[last_idx]);
	return (j);
}

static void	ft_swap(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}
