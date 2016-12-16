/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrimino_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:00:15 by lbogar            #+#    #+#             */
/*   Updated: 2016/11/18 18:00:16 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tet	*ft_create_tetrimino(void)
{
	t_tet *piece;

	piece = (t_tet*)malloc(sizeof(t_tet));
	if (piece == NULL)
		return (NULL);
	return (piece);
}

static int		ft_find_origin(char *tetrimino, int index)
{
	while (tetrimino[index] != '#')
		++index;
	return (index);
}

static t_tet	*ft_read_tetrimino(char *tetrimino, int index)
{
	t_tet	*piece;
	int		newline;
	int		origin;
	int		i;

	i = 0;
	index = ft_find_origin(tetrimino, index);
	origin = index;
	newline = 0;
	piece = ft_create_tetrimino();
	while (i < 4)
	{
		if (tetrimino[index] == '\n')
		{
			++newline;
			origin += 5;
		}
		if (tetrimino[index] == '#')
		{
			piece->x[i] = (index - origin);
			piece->y[i++] = newline;
		}
		index++;
	}
	return (piece);
}

t_tet			**ft_read_all_tetrimino(char *tetrimino)
{
	t_tet	**puzzle;
	int		count;
	int		i;
	int		j;
	char	c;

	count = (ft_strlen(tetrimino) + 1) / 21;
	puzzle = (t_tet**)malloc(sizeof(t_tet*) * (count + 1));
	i = 0;
	j = 0;
	c = 'A';
	while (j < count)
	{
		puzzle[j] = ft_read_tetrimino(tetrimino, i);
		ft_print_tetrimino(puzzle[j]);
		puzzle[j]->c = c;
		c++;
		i += 21;
		j++;
	}
	puzzle[j] = NULL;
	return (puzzle);
}
