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

int		ft_exclude_hidden(struct dirent *pdirent)
{
	if (ft_strcmp(pdirent->d_name, ".") == 0)
		return (1);
	else if (ft_strcmp(pdirent->d_name, "..") == 0)
		return (1);
	else
		return (0);
}

int		ft_read_dir(DIR *pDIR, t_format *flag)
{
	struct dirent *pdirent;
	struct stat *buf;

	(void)flag;
	buf = malloc(sizeof(buf));
	if (pDIR == NULL)
		return (1);
	while ((pdirent = readdir(pDIR)) != NULL)
	{
		printf("%s\n", pdirent->d_name);
		stat(pdirent->d_name, buf);
		if (S_ISDIR(buf->st_mode) && ft_exclude_hidden(pdirent) == 0)
			ft_read_dir(opendir(pdirent->d_name), flag);
	}
	free(buf);
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
	DIR 			*pDIR;

	i = 1;
	flag = (t_format*)ft_memalloc(sizeof(t_format));
	if (argc == 1)
	{
		pDIR = opendir(ft_find_dir(envp));
		ft_read_dir(pDIR, flag);
	}
	if (argc >= 2)
	{
		ft_initialize_flag(flag);
		if (ft_parse_flag(argv, flag))
			return (1);
		if (flag->found == 1)
			i++;
		while (argv[i])
			ft_read_dir(opendir(argv[i++]), flag);
	}
	free (flag);
	return (0);
}
