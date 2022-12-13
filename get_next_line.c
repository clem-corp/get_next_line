/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:15:30 by clacaill          #+#    #+#             */
/*   Updated: 2022/12/13 18:38:26 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	int			nb_read;

	// line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buff, 0) == -1)
		return (NULL);
	nb_read = read(fd, buff, BUFFER_SIZE);
	buff[nb_read] = '\0';
	if(buff[0] == '\0')
		return ("null");
	return (buff);
}

int main()
{
	int fd;

	fd = open("cat.txt", O_RDONLY);
	printf("1%s\n", get_next_line(fd));
	printf("2%s\n", get_next_line(fd));
/* 	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd)); */
	close(fd);
	return (0);
}