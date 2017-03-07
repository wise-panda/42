/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:12:06 by lbogar            #+#    #+#             */
/*   Updated: 2016/11/08 13:12:06 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char			*ft_join(int count, va_list *vars)
{
	char *next_arg;
	char *join;
	char *temp;

	next_arg = va_arg(*vars, char*);
	join = ft_strdup(next_arg);
	count--;
	while (count)
	{
		next_arg = va_arg(*vars, char*);
		temp = ft_strjoin(join, next_arg);
		free(join);
		join = ft_strdup(temp);
		free(temp);
		count--;
	}
	return (join);
}

char				*ft_strnjoin(int count, ...)
{
	char	*join;
	va_list	vars;

	va_start(vars, count);
	if (count <= 0)
		return (NULL);
	join = ft_join(count, &vars);
	va_end(vars);
	return (join);
}
