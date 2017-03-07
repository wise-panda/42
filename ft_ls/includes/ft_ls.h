/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 10:04:00 by lbogar            #+#    #+#             */
/*   Updated: 2016/12/16 10:04:35 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <stdio.h>

typedef struct	s_format
{
	int			found;
	int			l;
	int			rec;
	int			a;
	int			r;
	int			t;
}				t_format;

size_t			ft_strlen(const char *s);
char			*ft_strnjoin(int count, ...);
char			*ft_strnew(size_t size);
char			*ft_strcpy(char *dst, const char *src);
int				ft_read_dir(char *name, t_format *flag);
int				ft_read_dir_r(char *dir_name, t_format *flag);
char			*ft_strchr(const char *s, int c);
void			*ft_memalloc(size_t size);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strjoin(char const *s1, char const *s2);

#endif
