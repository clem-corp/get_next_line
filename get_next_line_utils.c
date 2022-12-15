/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:15:55 by clacaill          #+#    #+#             */
/*   Updated: 2022/12/15 19:17:14 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

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
