/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fliraud- <fliraud-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:44:01 by fliraud-          #+#    #+#             */
/*   Updated: 2026/04/27 16:02:00 by fliraud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_file_cat(int fd, char **remaining)
{
	int		bytes_read;
	char	*buffer;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(buffer);
		free(*remaining);
		*remaining = NULL;
		return (NULL);
	}
	if (bytes_read == 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

static int	update_remaining(char **rem, char *rem2, char **line, int i)
{
	int	j;

	j = 0;
	*rem = ft_calloc(ft_strlen(rem2) - i, sizeof(char));
	if (!(*rem))
	{
		free(rem2);
		free(*line);
		return (0);
	}
	j = 0;
	while (rem2[i + 1 + j])
	{
		(*rem)[j] = rem2[i + 1 + j];
		j++;
	}
	free(rem2);
	return (1);
}

static int	ft_split_lines_util(char **remaining, char **line, int i)
{
	int		j;
	char	*remaining2;

	j = 0;
	*line = ft_calloc(i + 2, sizeof(char));
	if (!(*line))
	{
		free(*remaining);
		*remaining = NULL;
		return (0);
	}
	while (j < i)
	{
		(*line)[j] = (*remaining)[j];
		j++;
	}
	(*line)[i] = '\n';
	remaining2 = *remaining;
	return (update_remaining(remaining, remaining2, line, i));
}

static char	*ft_split_lines(char **remaining, int i)
{
	char	*line;

	line = NULL;
	if (*remaining && **remaining == '\0')
	{
		free(*remaining);
		*remaining = NULL;
		return (NULL);
	}
	while ((*remaining) && (*remaining)[i] && (*remaining)[i] != '\n')
		i++;
	if ((*remaining) && (*remaining)[i] == '\n')
	{
		if (!ft_split_lines_util(remaining, &line, i))
			return (NULL);
	}
	else if ((*remaining) && **remaining != '\0')
	{
		line = ft_strdup(*remaining);
		free(*remaining);
		*remaining = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*remaining[FD_MAX];
	char		*remaining2;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FD_MAX)
		return (NULL);
	while (!ft_strchr(remaining[fd], '\n'))
	{
		buffer = read_file_cat(fd, &remaining[fd]);
		if (!buffer)
			break ;
		remaining2 = remaining[fd];
		remaining[fd] = ft_strjoin(remaining2, buffer);
		free(remaining2);
		free(buffer);
		if (!remaining[fd])
			return (NULL);
	}
	return (ft_split_lines(&remaining[fd], 0));
}
