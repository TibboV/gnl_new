/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_OLD.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvera <tvera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:47:01 by tvera             #+#    #+#             */
/*   Updated: 2021/08/11 11:10:57 by tvera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_find_n(char *save)
{
	int	i;

	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*split_lines(t_gnl *gnl, char **save, int n)
{
	char	*str;
	int		len;

	(*save)[n] = '\0';
	gnl->line = ft_strdup(*save);
	len = ft_strlen(*save + n + 1);
	if (len == 0)
	{
		free(*save);
		*save = 0;
		return (gnl->line);
	}
	str = ft_strdup(*save + n + 1);
	free(*save);
	*save = str;
	return (gnl->line);
}

static char	*ft_return(t_gnl *gnl, char **save)
{
	int	n;

	n = ft_find_n(*save);
	if (*save && n >= 0)
		return (split_lines(gnl, save, n));
	else if (*save)
	{
		gnl->line = *save;
		*save = 0;
		return (gnl->line);
	}
	gnl->line = ft_strdup("");
	return (gnl->line);
}

char *get_next_line(int fd)
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
		n = ft_find_n(save);
		if (n >= 0)
			return (split_lines(&gnl, &save, n));
	}
	return (ft_return(&gnl, &save));
}
