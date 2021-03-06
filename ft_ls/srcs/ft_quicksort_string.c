/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:31:21 by lbogar            #+#    #+#             */
/*   Updated: 2017/03/13 11:31:22 by lbogar           ###   ########.fr       */
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
	char	*pivot;
	int 	partition_index;
	int 	current_element;

	pivot = array[end]->filename;
	partition_index = start;
	current_element = start;
	while (current_element < end)
	{
		if (ft_strcmp(array[current_element]->filename, pivot) <= 0)
		{
			swap(array, current_element, partition_index);
			partition_index++;
		}
		current_element++;
	}
	swap(array, partition_index, end);
	return (partition_index);
}

void		ft_quicksort_string(t_metadata **array, int start, int end)
{
	int partition_index;

	if (start < end)
	{
		partition_index = partition(array, start, end);
		ft_quicksort_string(array, start, (partition_index - 1));
		ft_quicksort_string(array, (partition_index + 1), end);
	}
}
