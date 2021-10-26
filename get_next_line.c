/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:54:18 by mbarylak          #+#    #+#             */
/*   Updated: 2021/10/22 18:23:54 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char **file)
{
	if (*file)
	{
		free(*file);
		*file = NULL;
	}
	return (NULL);
}

static char	*get_line(char **file, int fd)
{
	char	*aux;
	char	*line;
	int		i;

	aux = file[fd];
	i = ft_strchr(aux, '\n');
	line = ft_substr(aux, 0, i + 1);
	file[fd] = ft_substr(aux, i + 1, (ft_strlen(aux) - i));
	ft_free(&aux);
	if (!file[fd])
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*file[FD_SIZE];
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
				return (ft_free(file + fd));
			buf[ret] = '\0';
			file[fd] = ft_strjoin(file[fd], buf);
		}
		else
			return (get_line(file, fd));
	}
	return (ft_free(file + fd));
}
