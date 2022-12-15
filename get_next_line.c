/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:15:30 by clacaill          #+#    #+#             */
/*   Updated: 2022/12/15 17:29:00 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			nb_read;

	nb_read = -1;
	line = "";
	line = ft_strjoin(line , buff);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buff, 0) == -1)
		return (NULL);
	while (!ft_strchr(line, '\n') && nb_read != 0)
	{
		nb_read = read(fd, buff, BUFFER_SIZE);
		if(nb_read == -1)
			return (NULL);
		buff[nb_read] = '\0';
		line = ft_strjoin(line , buff);
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
		return (NULL);
	return (line);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != c % 256 && *s != '\0')
		s++;
	if (*s != '\0' || c == '\0')
		return ((char *)s);
	return ((void *)0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i1;
	int		i2;
	int		ln;
	char	*dest;

	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	ln = i1 + i2;
	dest = malloc((ln + 1) * sizeof(char));
	if (!dest)
		return ((void *)0);
	i1 = -1;
	i2 = -1;
	while (s1[++i1])
		dest[i1] = s1[i1];
	while (s2[++i2])
		dest[i1 + i2] = s2[i2];
	while (i1 + i2 < ln + 1)
		dest[i1 + i2++] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* int main()
{
	int fd;
	int i;
	int j;
	fd = open("cat.txt", O_RDONLY);
	i = 15;
	while(i-- > 0)
		printf("%s", get_next_line(fd));
	close(fd);
	return (0);
} */