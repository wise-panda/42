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

int		ft_print_dir(char *dirname)
{
	int						i;
	t_directory		*dir;

	i = 0;
	dir = ft_create_tdir(dirname);
	ft_quicksort_timestamp(dir->files, 0, (dir->dirlen - 2));
	while (dir->files[i])
	{
		printf("%s\n", dir->files[i]->filename);
		printf("%zu\n", dir->files[i]->timestamp);
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
		ft_print_dir(ft_find_pwd(envp));
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
