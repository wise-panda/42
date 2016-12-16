/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:20:30 by lbogar            #+#    #+#             */
/*   Updated: 2016/11/21 17:20:32 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_array(char **array)
{
	int i;

	i = 0;
	while (array[i] != NULL)
	{
		ft_putstr(array[i]);
		ft_putchar('\n');
		++i;
	}
}

void	ft_print_tetrimino(t_tet *tetrimino)
{
	int i;

	i = 0;
	while (i < 4)
	{
		ft_putnbr(tetrimino->x[i]);
		ft_putchar(' ');
		ft_putnbr(tetrimino->y[i]);
		ft_putchar('\n');
		++i;
	}
	ft_putchar('\n');
}
