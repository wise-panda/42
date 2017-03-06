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
		flag->R = 1;
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

int		ft_read_dir(char *name, t_format *flag)
{
	DIR						*pDIR;
	struct dirent *pdirent;

	(void)flag;
	if (!(pDIR = opendir(name)))
		return (1);
	while ((pdirent = readdir(pDIR)) != NULL)
	{
		if (pdirent->d_name[0] == '.')
			continue ;
		printf("%s\n", pdirent->d_name);
	}
	closedir(pDIR);
	return (0);
}

int		ft_isdir(char *name)
{
	struct stat *pstat;

	if ((pstat = (struct stat*)ft_memalloc(sizeof(struct stat))) == NULL)
		return (0);
	if (lstat(name, pstat) == -1)
		return (0);
	if ((S_IFDIR & pstat->st_mode) == S_IFDIR)
	{
		free(pstat);
		return (1);
	}
	else
	{
		free(pstat);
		return (0);
	}
}

int		ft_read_dir_R(char *dir_name, t_format *flag)
{
	char					*path;
	char					*temp;
	DIR						*pDIR;
	struct dirent *pdirent;

	(void)flag;
	if (!(pDIR = opendir(dir_name)))
		return (1);
	printf("folder: %s\n", dir_name);
	ft_read_dir(dir_name, flag);
	printf("\n");
	while ((pdirent = readdir(pDIR)) != NULL)
	{
		if (pdirent->d_name[0] == '.')
			continue ;
		temp = ft_strjoin(dir_name, "/");
		path = ft_strjoin(temp, pdirent->d_name);
		free(temp);
		if (ft_isdir(path))
			ft_read_dir_R(path, flag);
		free(path);
	}
	closedir(pDIR);
	return (0);
}

void	ft_initialize_flag(t_format *flag)
{
	flag->found = 0;
	flag->l = 0;
	flag->R = 0;
	flag->a = 0;
	flag->r = 0;
	flag->t = 0;
}

int		main(int argc, char **argv, char **envp)
{
	int				i;
	t_format	*flag;

	i = 1;
	flag = (t_format*)ft_memalloc(sizeof(t_format));
	if (argc == 1)
		ft_read_dir(ft_find_dir(envp), flag);
	if (argc >= 2)
	{
		ft_initialize_flag(flag);
		if (ft_parse_flag(argv, flag))
			return (1);
		if (flag->found == 1)
			i++;
		while (argv[i])
		{
			ft_read_dir_R(argv[i], flag);
			i++;
		}
	}
	free (flag);
	return (0);
}
