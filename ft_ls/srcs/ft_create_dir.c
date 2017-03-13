/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:46:33 by lbogar            #+#    #+#             */
/*   Updated: 2017/03/13 11:46:34 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_dirlen(char *dirname)
{
	DIR						*pdir;
	struct dirent	*pdirent;
	int						len;

	len = 0;
	if (!(pdir = opendir(dirname)))
		return (0);
	while ((pdirent = readdir(pdir)) != NULL)
	{
		if (pdirent->d_name[0] == '.')
			continue ;
		len++;
	}
	closedir(pdir);
	return (len);
}

t_metadata	**ft_create_tmeta_array(int array_size)
{
	t_metadata 		**files;
	int						i;

	i = 0;
	files = (t_metadata**)ft_memalloc(sizeof(t_metadata*) * array_size);
	while (i < (array_size - 1))
	{
		files[i] = (t_metadata*)ft_memalloc(sizeof(t_metadata));
		i++;
	}
	files[i] = NULL;
	return (files);
}

int					ft_parse_filename(char *dirname, t_metadata **files)
{
	DIR						*pdir;
	struct dirent	*pdirent;
	int						i;

	i = 0;
	if (!(pdir = opendir(dirname)))
		return (1);
	while ((pdirent = readdir(pdir)) != NULL)
	{
		if (pdirent->d_name[0] == '.')
			continue ;
		files[i]->filename = ft_strdup(pdirent->d_name);
		files[i]->namelen = ft_strlen(pdirent->d_name);
		i++;
	}
	closedir(pdir);
	return (0);
}

int				ft_parse_timestamp(t_metadata **files)
{
	struct	stat *pstat;
	int			i;

	i = 0;
	if ((pstat = (struct stat*)ft_memalloc(sizeof(struct stat))) == NULL)
		return (1);
	while (*files)
	{
		if (lstat((*files)->filename, pstat) == -1)
			return (1);
		(*files)->timestamp = pstat->st_ctimespec.tv_sec;
		files++;
	}
	free(pstat);
	return (0);
}

t_directory	*ft_create_tdir(char *dirname)
{
	t_directory		*dir;

	dir = ft_memalloc(sizeof(t_directory));
	dir->dirname = ft_strdup(dirname);
	dir->dirlen = ft_dirlen(dirname) + 1;
	dir->files = ft_create_tmeta_array(dir->dirlen);
	ft_parse_filename(dirname, dir->files);
	ft_parse_timestamp(dir->files);
	return (dir);
}
