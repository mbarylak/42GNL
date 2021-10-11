#include "get_next_line.h"

static int	is_nl(char *buf)
{
	int	i;

	if (!buf)
		return (0);
	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*get_line(char *s)
{
	char	*temp;
	char	*line;
	int		i;

	if (!s)
		return (NULL);
	temp = (char *) malloc(ft_strlen(s) + 1);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\n';
	temp[i++] = '\0';
	line = ft_strdup(temp);
	free(temp);
	free(s);
	return (line);
}

static char	*give_line(char **s, int fd)
{
	char	*temp;

	if (!s[fd] || fd < 0)
		return (NULL);
	temp = ft_strdup(s[fd]);
	s[fd] = ft_strchr(s[fd], '\n');
	return (get_line(temp));
}

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	static char	*line[256];
	int		ret;

	if (!fd || BUFFER_SIZE <= 0)
		return (NULL);
	if (!line[fd])
		line[fd] = ft_strdup("");
	ret = 1;
	while (ret > 0)
	{
		if (!is_nl(line[fd]))
		{	
			ret = read(fd, buf, BUFFER_SIZE);
			if (ret <= 0)
				return (NULL);
			line[fd] = ft_strjoin(line[fd], buf);
		}
		else
			return (give_line(line, fd));
	}
	return (NULL);
}
