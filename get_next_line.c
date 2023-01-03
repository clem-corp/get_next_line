/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:15:30 by clacaill          #+#    #+#             */
/*   Updated: 2023/01/03 19:05:44 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_back_n(char *line, char *buff);

char	*return_function(char *line, char *buff)
{
	if (ft_strchr(line, '\n'))
		ft_back_n(line, buff);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			nb_read;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buff, 0) == -1)
		return (NULL);
	line = "";
	line = ft_strjoin(line, buff);
	if (!line)
		return (NULL);
	nb_read = -1;
	while (!ft_strchr(line, '\n') && nb_read != 0)
	{
		nb_read = read(fd, buff, BUFFER_SIZE);
		if (nb_read == -1)
			return (NULL);
		buff[nb_read] = '\0';
		tmp = line;
		line = ft_strjoin(tmp, buff);
		free(tmp);
		if (!line)
			return (NULL);
	}
	return (return_function(line, buff));
}

void	ft_back_n(char *line, char *buff)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	while (line[j + i] && line[j + i + 1])
	{
		buff[j] = line[j + i + 1];
		j++;
	}
	buff[j] = '\0';
	if (line[i])
		line[i + 1] = '\0';
}
