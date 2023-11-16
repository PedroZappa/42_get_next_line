/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:23:57 by passunca          #+#    #+#             */
/*   Updated: 2023/11/16 14:59:31 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && *s1)
		str[i++] = *s1++;
	while (s2 && *s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

/* Get the length of a givengiven 'str' */
int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	if (str)
		while (str[len])
			++len;
	return (len);
}

/* Find a char in a given 'str' */
char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		++s;
	}
	if ((*s == '\0') && (c == '\0'))
		return ((char *)s);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = '\0';
}
