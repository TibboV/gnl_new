/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_OLD.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvera <tvera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:48:02 by tvera             #+#    #+#             */
/*   Updated: 2021/08/16 12:39:58 by tvera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		leng;
	int		i;

	leng = ft_strlen(s1);
	i = 0;
	dest = (char *)malloc(sizeof(*dest) * leng + 1);
	if (!dest)
		return (NULL);
	while (i < leng)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < dstsize)
		i++;
	while (src[j] && i + j + 1 < dstsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i != dstsize)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	int		len1;
	int		len2;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		dst = (char *)malloc(sizeof(*s1) * (len1 + len2 + 1));
		if (dst == NULL)
			return (NULL);
		ft_strlcpy(dst, s1, len1 + 1);
		free(s1);
		ft_strlcat(dst + len1, s2, len2 + 1);
		return (dst);
	}
	else if (!(s1) || !(s2))
	{
		if (!s1)
			return (ft_strdup(s2));
		else
			return (ft_strdup(s1));
	}
	return (NULL);
}
