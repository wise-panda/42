/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_quicksort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:31:21 by lbogar            #+#    #+#             */
/*   Updated: 2017/03/13 11:31:22 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		partition(int *array, int left, int right)
{
	int pivot;
	int i;
	int j;

	pivot = array[right];
	i = (left - 1);
	j = left;
	while (j <= (right - 1))
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
		j++;
	}
	swap(&array[i + 1], &array[right]);
	return (i + 1);
}

void		quicksort(int *array, int left, int right)
{
	int j;

	if (left < right)
	{
		j = partition(array, left, right);
		quicksort(array, left, (j - 1));
		quicksort(array, (j + 1), right);
	}
}
