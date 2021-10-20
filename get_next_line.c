#include "get_next_line.h"

char	*get_line(char **file, int fd)
{
	char	*aux;
	char	*line;
	int		i;

	if (!file[fd])
		return (NULL);
	aux = ft_strdup(file[fd]);
	free(file[fd]);
	i = ft_strchr(aux, '\n');
	line = ft_substr(aux, 0, i + 1);
	file[fd] = ft_substr(aux, i + 1, (ft_strlen(aux) - i));
	if (!file[fd])
	{
		free(file[fd]);
		file[fd] = NULL;
	}
	free(aux);
	return (line);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*file[FD_SIZE];
	char		*line;
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!file[fd])
		file[fd] = ft_strdup("");
	ret = 1;
	while (ret > 0)
	{
		if (ft_strchr(file[fd], '\n') == -1)
		{
			ret = read(fd, buf, BUFFER_SIZE);
			if (ret <= 0)
				return (NULL);
			buf[ret] = '\0';
			file[fd] = ft_strjoin(file[fd], buf);
		}
		else
		{
			line = get_line(file, fd);
			return (line);
		}
	}
	return (NULL);
}
