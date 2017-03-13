/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:38:22 by lbogar            #+#    #+#             */
/*   Updated: 2017/03/13 11:38:23 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Output would ideally not print out folder name for top directory,
** and not print out a trailing newline after the last entry.
*/

int		ft_isdir(char *path)
{
	(void)path;
	return (0);
}

int		ft_recurse(char *dir_name, t_format *flag)
{
	char					*path;
	DIR						*pdir;
	struct dirent			*pdirent;

	(void)flag;
	if (!(pdir = opendir(dir_name)))
		return (1);
	printf("%s:\n", dir_name);
	ft_print_dir(dir_name);
	printf("\n");
	while ((pdirent = readdir(pdir)) != NULL)
	{
		if (pdirent->d_name[0] == '.')
			continue ;
		path = ft_strnjoin(3, dir_name, "/", pdirent->d_name);
		if (ft_isdir(path))
		{
			ft_recurse(path, flag);
		}
		free(path);
	}
	closedir(pdir);
	return (0);
}
