#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define FD_SIZE 1024

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

size_t	ft_strlen(char *s);
int		ft_strchr(char *s, int c);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);

#endif
