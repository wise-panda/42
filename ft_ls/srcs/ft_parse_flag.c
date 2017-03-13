/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:30:37 by lbogar            #+#    #+#             */
/*   Updated: 2017/03/13 11:30:38 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_initialize_flag(t_format *flag)
{
	flag->found = 0;
	flag->l = 0;
	flag->rec = 0;
	flag->a = 0;
	flag->r = 0;
	flag->t = 0;
}

int		ft_valid_flag(char c)
{
	if (c == 'l' || c == 'R' || c == 'a' || c == 'r' || c == 't')
		return (1);
	else
		return (0);
}

void	ft_assign_flag(t_format *flag, char type)
{
	if (type == 'l')
		flag->l = 1;
	if (type == 'R')
		flag->rec = 1;
	if (type == 'a')
		flag->a = 1;
	if (type == 'r')
		flag->r = 1;
	if (type == 't')
		flag->t = 1;
}

int		ft_parse_flag(char **argv, t_format *flag)
{
	int		i;

	i = 1;
	if (argv[1][0] == '-')
		while (argv[1][i])
		{
			if (ft_valid_flag(argv[1][i]))
			{
				flag->found = 1;
				ft_assign_flag(flag, argv[1][i]);
			}
			else
				return (1);
			i++;
		}
	return (0);
}
