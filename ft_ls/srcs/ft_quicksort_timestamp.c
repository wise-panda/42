/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort_timestamp.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:06:45 by lbogar            #+#    #+#             */
/*   Updated: 2017/03/13 14:06:46 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		swap(t_metadata **array, int a, int b)
{
	t_metadata *temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

static int		partition(t_metadata **array, int start, int end)
{
	size_t pivot;
	int    partition_index;
	int    current_element;

	pivot = array[end]->timestamp;
	partition_index = start;
	current_element = start;
	while (current_element < end)
	{
		if (array[current_element]->timestamp <= pivot)
		{
			swap(array, current_element, partition_index);
			partition_index++;
		}
		current_element++;
	}
	swap(array, partition_index, end);
	return (partition_index);
}

void		ft_quicksort_timestamp(t_metadata **array, int start, int end)
{
	int partition_index;

	if (start < end)
	{
		partition_index = partition(array, start, end);
		ft_quicksort_string(array, start, (partition_index - 1));
		ft_quicksort_string(array, (partition_index + 1), end);
	}
}
