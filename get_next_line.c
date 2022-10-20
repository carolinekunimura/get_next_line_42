/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:14:47 by ckunimur          #+#    #+#             */
/*   Updated: 2022/10/18 16:56:37 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	line = takenextline(fd);
	return (line);
}

char	*takenextline(int fd)
{
	char	*buffer;
	char	*line;
	size_t	reader;

	line = NULL;
	if (fd > 0 && BUFFER_SIZE > 0)
	{
		while (line == NULL)
		{
			buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
			reader = read(fd, buffer, BUFFER_SIZE);
			if (reader == 0)
			{
				buffer[reader] = '\0';
				line = ft_makestr(buffer, '\0');
				free(buffer);
				return (line);
			}
			line = ft_makestr(buffer, '\n');
			free(buffer);
		}
	}
	return (line);
}

char	*ft_makestr(const char *buffer, char c)
{
	char		*line;
	char		*rmd;
	static char	*remainder;

	if (c == '\0' && !ft_strchr(remainder, '\n'))
	{
		line = remainder;
		remainder = NULL;
		return (line);
	}
	else
		c = '\n';
	buffer = ft_strjoin(remainder, buffer);
	rmd = ft_strchr(buffer, c);
	free(remainder);
	remainder = NULL;
	if (!rmd)
	{
		remainder = ft_strdup(buffer);
		free((char *)buffer);
		return (NULL);
	}
	if (rmd[1] != '\0')
		remainder = ft_strdup(rmd + 1);
	line = ft_substr(buffer, 0, (ft_strlen(buffer)) - (ft_strlen(remainder)));
	free((char *)buffer);
	return (line);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*buffer;
	size_t	size_t_max;

	i = 0;
	buffer = NULL;
	size_t_max = -1;
	if (nmemb * size == 0 || (size != 0 && nmemb > size_t_max / size))
		return (NULL);
	buffer = malloc(nmemb * size);
	if (buffer == NULL)
		return (NULL);
	while (nmemb * size != i)
	{
		((char *)buffer)[i] = '\0';
		i++;
	}
	return (buffer);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*p;

	s_len = ft_strlen(s);
	i = 0;
	if (len >= s_len)
		len = (s_len - start);
	if (start >= s_len)
	{
		return (ft_calloc(1, (sizeof(char))));
	}
	p = ft_calloc(len + 1, (sizeof(char)));
	if (s)
	{
		while (i < len && s[start + i] != '\0')
		{
			p[i] = s[start + i];
			i++;
		}
		p[i] = '\0';
	}
	return (p);
}
