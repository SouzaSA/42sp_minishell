/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:07:09 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/13 11:18:30 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_transfer_values(int *values, int *aux_array, int start, int end);
static void	ft_merge(int *values, int start, int mid, int end);

/* ************************************************************************** */
/* merge sort - divides the vector into two parts recursively up to size 1,   */
/* then joining does puts the values in order.                                */
/* ************************************************************************** */
void	ft_merge_sort(int *values, int start, int end)
{
	int	mid;

	if (start < end)
	{
		mid = (start + end) / 2;
		ft_merge_sort(values, start, mid);
		ft_merge_sort(values, mid + 1, end);
		ft_merge(values, start, mid, end);
	}
}

static void	ft_merge(int *values, int start, int mid, int end)
{
	int	i;
	int	j;
	int	k;
	int	*aux_array;

	i = start;
	j = mid + 1;
	k = 0;
	aux_array = (int *)malloc((end - start + 1) * sizeof(int));
	while (i <= mid && j <= end)
	{
		if (values[i] < values[j])
			aux_array[k] = values[i++];
		else
			aux_array[k] = values[j++];
		k++;
	}
	while (i <= mid)
		aux_array[k++] = values[i++];
	while (j <= end)
		aux_array[k++] = values[j++];
	ft_transfer_values(values, aux_array, start, end);
	free(aux_array);
}

static void	ft_transfer_values(int *values, int *aux_array, int start, int end)
{
	int	k;

	k = start;
	while (k <= end)
	{
		values[k] = aux_array[k - start];
		k++;
	}
}
