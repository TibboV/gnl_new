/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvera <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:22:14 by tvera             #+#    #+#             */
/*   Updated: 2021/08/16 14:50:38 by tvera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int		fd = 0;

//	fd = open("text.txt", O_RDONLY);
//	fd = open("files/empty", O_RDONLY);
//	fd = open("files/nl", O_RDONLY);
//	fd = open("files/41_no_nl", O_RDONLY);
//	fd = open("files/41_with_nl", O_RDONLY);
//	fd = open("files/42_no_nl", O_RDONLY);
//	fd = open("files/42_with_nl", O_RDONLY);
//	fd = open("files/43_no_nl", O_RDONLY);
//	fd = open("files/43_with_nl", O_RDONLY);
	fd = open("files/multiple_nlx5", O_RDONLY);
//	fd = open("files/multiple_line_no_nl", O_RDONLY);
//	fd = open("files/multiple_line_with_nl", O_RDONLY);
//	fd = open("files/alternate_line_nl_no_nl", O_RDONLY);
//	fd = open("files/alternate_line_nl_with_nl", O_RDONLY);
//	fd = open("files/big_line_no_nl", O_RDONLY);
//	fd = open("files/big_line_with_nl", O_RDONLY);
	
	printf("fd : %i\n", fd);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
/*	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
*/
}
