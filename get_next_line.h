#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
char	*ft_strjoin1(char **s1, char const *s2, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strndup1(const char *str, int i);
void	*ft_calloc(int num, int size);
int		ft_strchr(char *str);
int		string_join(char **buf, char **line, int count_byte);
char	*minus_string(char *buf, int i);
int		error_free(char **buf, char **line);
int		while_read(char **buf, char **line, int fd);

#endif
