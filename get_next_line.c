/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:15:30 by clacaill          #+#    #+#             */
/*   Updated: 2022/12/15 19:17:34 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			nb_read;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buff, 0) == -1)
		return (NULL);
	
	nb_read = -1;
	line = "";
	line = ft_strjoin(line , buff);
	while (!ft_strchr(line, '\n') && nb_read != 0)
	{
		nb_read = read(fd, buff, BUFFER_SIZE);
		if(nb_read == -1)
			return (NULL);
		buff[nb_read] = '\0';
		tmp = line;
		line = ft_strjoin(tmp , buff);
		free(tmp);
	}
	if(ft_strchr(line, '\n'))
	{
		int i = 0;
		int j = 0;
		while(line[i] && line[i] != '\n')
			i++;
		while (line[j + i] && line[j + i + 1])
		{
			buff[j] = line[j + i + 1];
			j++;
		}
		buff[j] = '\0';
		if(line[i])
			line[i + 1] = '\0';
	}
	if(line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/* int main()
{
	int fd;
	int i;
	fd = open("cat.txt", O_RDONLY);
	char *gnl;
	i = 17;
	while(i-- > 0)
	{
		gnl = get_next_line(fd);
		printf("%s", gnl);
		free(gnl);
	}
	close(fd);
	return (0);
} */