/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:00:04 by lbogar            #+#    #+#             */
/*   Updated: 2016/12/03 17:00:05 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		realloc_str(char **line_copy, size_t size)
{
	char	*temp;
	int		old_size;

	old_size = ft_strlen(*line_copy);
	if (!(temp = ft_strnew(size)))
		return (-1);
	ft_memcpy(temp, *line_copy, old_size);
	free(*line_copy);
	*line_copy = ft_strdup(temp);
	free(temp);
	return (0);
}

int		strsub_newline(char **line_copy, char **line)
{
	char	*temp;
	int		line_len;
	int		read_len;

	if (*line_copy == NULL)
		*line_copy = ft_strnew(BUFF_SIZE);
	if (ft_strchr(*line_copy, '\n') == NULL)
		return (1);
	line_len = ((ft_strchr(*line_copy, '\n')) - *line_copy);
	read_len = ft_strlen(*line_copy);
	temp = ft_strsub(*line_copy, (line_len + 1), read_len);
	*line = ft_strsub(*line_copy, 0, (line_len));
	free(*line_copy);
	*line_copy = ft_strdup(temp);
	free(temp);
	return (0);
}

int		eof_exit(char **line_copy, char **buffer, char **line)
{
	if (ft_strlen(*line_copy))
	{
		if (!(*line = ft_strdup(*line_copy)))
			return (-1);
		ft_strdel(line_copy);
		ft_strdel(buffer);
		return (1);
	}
	return (0);
}

int		process_read(char **line_copy, char **buffer)
{
	int		line_len;
	int		buffer_len;
	char	*temp;

	line_len = ft_strlen(*line_copy);
	buffer_len = ft_strlen(*buffer);
	if (!*line_copy || (realloc_str(line_copy, (line_len + buffer_len + 1))) ||
		!(temp = ft_strjoin(*line_copy, *buffer)))
		return (-1);
	free(*line_copy);
	*line_copy = ft_strdup(temp);
	free(temp);
	ft_strdel(buffer);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char			*buffer;
	static char		*fd_x[MAX_FD];
	int				ret;

	if (fd < 0 || fd > 1024 || !line || BUFF_SIZE < 1)
		return (-1);
	if ((strsub_newline(&fd_x[fd], &(*line))) == 0)
		return (1);
	while ((ft_strchr(fd_x[fd], '\n')) == NULL)
	{
		buffer = ft_strnew(BUFF_SIZE);
		if ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
			if (process_read(&fd_x[fd], &buffer) == -1)
				return (-1);
		if (ret == 0)
			return (eof_exit(&fd_x[fd], &buffer, &(*line)));
		if (ret == -1)
			return (-1);
	}
	strsub_newline(&fd_x[fd], &(*line));
	return (1);
}
