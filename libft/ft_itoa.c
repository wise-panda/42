/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:47:05 by lbogar            #+#    #+#             */
/*   Updated: 2016/11/09 21:47:06 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		neg;
	long	num;

	neg = 0;
	num = (long)n;
	if (num < 0)
	{
		neg = 1;
		num *= -1;
	}
	len = ft_intlen(num) + neg;
	if ((str = ft_strnew(len--)) == NULL)
		return (NULL);
	if (num == 0)
		str[0] = '0';
	while (num)
	{
		str[len--] = (num % 10) + '0';
		num /= 10;
	}
	if (neg && str[0] != '0')
		str[0] = '-';
	return (str);
}
