/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_OLD.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvera <tvera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:47:48 by tvera             #+#    #+#             */
/*   Updated: 2021/08/13 15:23:23 by tvera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef	BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

typedef struct s_gnl
{
	char *line;
}	t_gnl;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strndup(const char *s1, int n);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int	ft_strchr(const char *s, char c);

#endif
