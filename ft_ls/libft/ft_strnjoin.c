/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:12:06 by lbogar            #+#    #+#             */
/*   Updated: 2016/11/08 13:12:06 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_realloc_str(char **str, size_t size)
{
	char	*temp;
	int		old_size;

	old_size = ft_strlen(*str);
	if (!(temp = ft_strnew(size)))
		return (-1);
	ft_memcpy(temp, *str, old_size);
	free(*str);
	*str = ft_strdup(temp);
	free(temp);
	return (0);
}

static char	*ft_join(int count, va_list *vars)
{
	int		i;
	char	*join;
	char	*next_arg;
	size_t	size;

	i = 1;
	if (count >= 1)
	{
		next_arg = va_arg(*vars, char*);
		size = ft_strlen(next_arg);
		join = ft_strdup(next_arg);
		//this is the problem ^^
	}
	while (i++ < count)
	{
		next_arg = va_arg(*vars, char*);
		if (next_arg == NULL)
			continue ;
		size += ft_strlen(next_arg);
		ft_realloc_str(&join, size);
		ft_strcat(join, next_arg);
	}
	return (join);
}

char	*ft_strnjoin(int count, ...)
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
