/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_find_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <lbogar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:45:13 by lbogar            #+#    #+#             */
/*   Updated: 2018/04/26 12:55:36 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_find_substr(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		++s1;
		++s2;
	}
	if (*s1 == '\0')
		return (1);
	else
		return (0);
}

char	*ft_find_pwd(char **envp)
{
	char	*dir;

	dir = "PWD=";
	while (*envp)
	{
		if (ft_find_substr(dir, *envp))
		{
			*envp = ft_strchr(*envp, '/');
			return (*envp);
		}
		++envp;
	}
	return (NULL);
}
