/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <lbogar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 10:04:00 by lbogar            #+#    #+#             */
/*   Updated: 2018/04/25 21:14:57 by lbo              ###   ########.fr       */
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
	int			found;
	int			l;
	int			rec;
	int			a;
	int			r;
	int			t;
}				t_format;

int				ft_read_dir(char *name, t_format *flag);
int				ft_read_dir_r(char *dir_name, t_format *flag);

#endif
