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

// if ((S_IFDIR & pstat->st_mode) == S_IFDIR)
// 	return (1);
// else
// 	return (0);

/*
** Output would ideally not print out folder name for top directory,
** and not print out a trailing newline after the last entry.
*/

// int		ft_read_dir_r(char *dir_name, t_format *flag)
// {
// 	char					*path;
// 	DIR						*pdir;
// 	struct dirent			*pdirent;
//
// 	(void)flag;
// 	if (!(pdir = opendir(dir_name)))
// 		return (1);
// 	printf("%s:\n", dir_name);
// 	ft_read_dir(dir_name, flag);
// 	printf("\n");
// 	while ((pdirent = readdir(pdir)) != NULL)
// 	{
// 		if (pdirent->d_name[0] == '.')
// 			continue ;
// 		path = ft_strnjoin(3, dir_name, "/", pdirent->d_name);
// 		if (ft_isdir(path))
// 		{
// 			ft_read_dir_r(path, flag);
// 		}
// 		free(path);
// 	}
// 	closedir(pdir);
// 	return (0);
// }

void	ft_initialize_flag(t_format *flag)
{
	flag->found = 0;
	flag->l = 0;
	flag->rec = 0;
	flag->a = 0;
	flag->r = 0;
	flag->t = 0;
}

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

int		ft_print_dir(char *dirname)
{
	int						i;
	t_directory		*dir;

	i = 0;
	dir = ft_create_tdir(dirname);
	while (dir->files[i])
	{
		printf("%s\n", dir->files[i]->filename);
		i++;
	}
	free(dir);
	return (0);
}

int		main(int argc, char **argv, char **envp)
{
	int				i;
	t_format		*flag;

	i = 1;
	flag = (t_format*)ft_memalloc(sizeof(t_format));
	if (argc == 1)
		ft_print_dir(ft_find_dir(envp));
	if (argc >= 2)
	{
		ft_initialize_flag(flag);
		if (ft_parse_flag(argv, flag))
			return (1);
		if (flag->found == 1)
			i++;
		while (argv[i])
		{
			ft_print_dir(argv[i]);
			i++;
		}
	}
	free(flag);
	return (0);
}
