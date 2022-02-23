#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(int num, int size)
{
	void	*mass;
	char	*str;
	int		i;

	mass = malloc(num * size);
	if (!mass)
		return (NULL);
	i = 0;
	str = (char *) mass;
	while (i < num * size)
	{
		str[i] = 0;
		i++;
	}
	return (mass);
}

char	*ft_strjoin1(char **s1, char const *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l1;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(*s1);
	i = -1;
	j = -1;
	str = malloc(sizeof(*str) * (l1 + len + 1));
	if (!str)
		return (NULL);
	while (++i < l1)
		str[i] = (*s1)[i];
	while (++j < len)
		str[i + j] = s2[j];
	str[i + j] = '\0';
	free(*s1);
	*s1 = NULL;
	return (str);
}

int	ft_strchr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strndup1(const char *str, int i)
{
	char	*s;
	int		len;
	int		j;

	len = ft_strlen(str);
	s = malloc(sizeof(*s) * (i + 1));
	if (!s)
		return (NULL);
	if (i > len)
		i = len;
	j = 0;
	while (j < i)
	{
		s[j] = str[j];
		j++;
	}
	s[j] = '\0';
	return (s);
}
