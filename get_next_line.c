#include "get_next_line.h"

char	*minus_string(char *buf, int i)
{
	char	*tmp;

	tmp = ft_strndup1(buf + i + 1, BUFFER_SIZE);
	free(buf);
	buf = tmp;
	return (buf);
}

int	error_free(char **buf, char **line)
{
	if (*buf)
	{
		free(*buf);
		*buf = NULL;
	}
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	return (-1);
}

int	string_join(char **buf, char **line, int count_byte)
{
	int	i;

	i = ft_strchr(*buf);
	if (i == -1)
	{
		*line = ft_strjoin1(line, *buf, count_byte);
		*buf = minus_string(*buf, count_byte);
		if (!*line || !*buf)
			return (error_free(&(*buf), &(*line)));
		return (0);
	}
	else
	{
		*line = ft_strjoin1(line, *buf, i);
		*buf = minus_string(*buf, i);
		if (!*line || !*buf)
			return (error_free(&(*buf), &(*line)));
		return (1);
	}
}

int	while_read(char **buf, char **line, int fd)
{
	int	i;
	int	count_byte;

	count_byte = BUFFER_SIZE;
	while (count_byte == BUFFER_SIZE)
	{
		count_byte = read(fd, *buf, BUFFER_SIZE);
		if (count_byte == -1)
			return (error_free(&(*buf), &(*line)));
		(*buf)[count_byte] = '\0';
		i = string_join(&(*buf), &(*line), count_byte);
		if (i != 0)
			return (i);
	}
	free(*buf);
	*buf = NULL;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*buf;
	int			i;

	if (!buf)
		buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (error_free(&buf, &(*line)));
	i = ft_strchr(buf);
	if (i >= 0)
	{
		*line = ft_strndup1(buf, i);
		buf = minus_string(buf, i);
		if (!*line || !buf)
			return (error_free(&buf, &(*line)));
		return (1);
	}
	else
		*line = ft_strndup1(buf, ft_strlen(buf));
	if (!(*line) || !buf)
		return (error_free(&buf, &(*line)));
	return (while_read(&buf, &(*line), fd));
}
