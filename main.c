/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:42:11 by msoklova          #+#    #+#             */
/*   Updated: 2024/04/01 19:52:54 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*next_line;
	int		count;

	count = 0;
	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break ;
		count++;
		printf("[%d]:%s\n", count, next_line);
		next_line = NULL;
	}
	close(fd);
	return (0);
}

//int	main(void)
//{
//	char * line;

//	const char *filename = "test.txt";
//    int fd = open(filename, O_RDONLY);
//	line = get_next_line(fd);
//	printf("%s", line);
//	free(line);
//	line = get_next_line(fd);
//	printf("%s", line);
//	free(line);
//	line = get_next_line(fd);
//	printf("%s", line);
//	free(line);
//	line = get_next_line(fd);
//	printf("%s", line);
//	free(line);
//	line = get_next_line(fd);
//	printf("%s", line);
//	free(line);
//	line = get_next_line(fd);
//	printf("%s", line);
//	free(line);
//	line = get_next_line(fd);
//	printf("%s", line);
//	free(line);
//	line = get_next_line(fd);
//	printf("%s", line);
//	free(line);
//	close(fd);
//}
