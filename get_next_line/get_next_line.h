/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:00:15 by lbogar            #+#    #+#             */
/*   Updated: 2016/12/03 17:00:17 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFF_SIZE 32
# define MAX_FD 1024

int		get_next_line(const int fd, char **line);
char	*ft_strnew(size_t size);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char const *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
void	ft_strdel(char **as);
#endif
