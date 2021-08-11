/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvera <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:22:14 by tvera             #+#    #+#             */
/*   Updated: 2021/08/11 11:45:43 by tvera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	char	*line;
	int		fd = 0;

	fd = open("text.txt", O_RDONLY);
	printf("%i\n", fd);
/*	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
*/
	while (get_next_line(fd) > 0)
		printf("%s\n", get_next_line(fd));
	return (0);
}
