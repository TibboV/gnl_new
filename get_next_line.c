/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_OLD.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvera <tvera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:47:01 by tvera             #+#    #+#             */
/*   Updated: 2021/08/16 16:35:16 by tvera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(const char *s1, int n)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(sizeof(*dest) * n + 1);
	if (!dest)
		return (NULL);
	while (i < n)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_find_n(char *save, char c)
{
	int	i;

	i = 0;
	while (save[i])
	{
		if (save[i] == c)
			return (i);
		i++;
	}
	return (0);
}

static char	*split_lines(t_gnl *gnl, char **save, int n)
{
	char	*str;
	int		len;

	gnl->line = ft_strndup(*save, n + 1);
	len = ft_strlen(*save + n + 1);
	str = ft_strdup(*save + n + 1);
	free(*save);
	*save = str;
	return (gnl->line);
}

static char	*ft_return(t_gnl *gnl, char **save)
{
	int	n;

	n = ft_find_n(*save, '\n');
	gnl->line = *save;
	if (*save[n] == '\n')
		return (split_lines(gnl, save, n));
	if (ft_strlen(*save) > 0)
	{
		*save = 0;
		return (gnl->line);
	}
	free(*save);
	*save = 0;
	return (0);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*save = NULL;
	int			read_size;
	int			n;
	t_gnl		gnl;

	if (fd < 0 || BUFFER_SIZE < 1
		|| read(fd, buff, 0) < 0)
		return (0);
	read_size = 1;
	while (read_size > 0)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		buff[read_size] = '\0';
		save = ft_strjoin(save, buff);
		n = ft_find_n(save, '\n');
		if (n > 0)
			return (split_lines(&gnl, &save, n));
	}
	return (ft_return(&gnl, &save));
}
