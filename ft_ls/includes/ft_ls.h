/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <lbogar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 10:04:00 by lbogar            #+#    #+#             */
/*   Updated: 2018/04/26 12:36:04 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <dirent.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct	s_format
{
	int					found;
	int					l;
	int					rec;
	int					a;
	int					r;
	int					t;
}							t_format;

int						ft_read_dir(char *name, t_format *flag);
int						ft_read_dir_r(char *dir_name, t_format *flag);
int						ft_print_dir(char *dirname);
void					ft_quicksort_string(t_metadata **array, int start, int end);
void					ft_quicksort_timestamp(t_metadata **array, int start, int end);
t_directory				*ft_create_tdir(char *dirname);
char					*ft_find_pwd(char **envp);
void					ft_initialize_flag(t_format *flag);
int						ft_parse_flag(char **argv, t_format *flag);

#endif
