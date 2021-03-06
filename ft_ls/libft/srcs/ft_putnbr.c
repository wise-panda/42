/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:47:38 by lbogar            #+#    #+#             */
/*   Updated: 2016/11/09 20:47:39 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long s;

	s = (long)n;
	if (s < 0)
	{
		ft_putchar('-');
		s = -s;
	}
	if (s >= 10)
	{
		ft_putnbr(s / 10);
		ft_putnbr(s % 10);
	}
	else
		ft_putchar(s + '0');
}
