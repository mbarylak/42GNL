/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:55:10 by mbarylak          #+#    #+#             */
/*   Updated: 2021/10/22 16:30:11 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define FD_SIZE 1024

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int		ft_strlen(char *s);
int		ft_strchr(char *s, int c);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);
char	*get_next_line(int fd);

#endif
