/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:53:51 by lbogar            #+#    #+#             */
/*   Updated: 2016/12/21 12:53:52 by lbogar           ###   ########.fr       */
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

char	*ft_find_dir(char **envp)
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

int		main(int argc, char **argv, char **envp)
{
	struct dirent *pdirent;
	DIR *pDIR;

	if (argc < 2)
		pDIR = opendir(ft_find_dir(envp));
	else
		pDIR = opendir(argv[1]);
	if (pDIR == NULL)
		return (1);
	while ((pdirent = readdir(pDIR)) != NULL)
	{
		printf("%s\n", pdirent->d_name);
	}
	closedir(pDIR);
	return (0);
}

// int		ft_ls()
// {
// 	return ()
// }
