/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:14:47 by ckunimur          #+#    #+#             */
/*   Updated: 2022/10/14 17:52:43 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = takenextline(fd);
	return (line);
}

char	*takenextline(int fd)
{
	char	*buffer;
	char	*line;
	int		reader;

	line = NULL;
	if (fd > 0 && BUFFER_SIZE > 0)
	{
		buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		while (line == (NULL))
		{
			reader = read(fd, buffer, BUFFER_SIZE);
			if (reader == 0)
				return (ft_makestr(buffer, '\0'));
			if (reader < BUFFER_SIZE && !ft_ifchr(reader, buffer, '\n'))
			{
				line = ft_calloc((reader + 2), sizeof(char));
				while (buffer)
					*line++ = *buffer++;
				*line++ = '\n';
				return (line);
			}
			line = ft_makestr(buffer, '\n');
		}
	}
	return (line);
}

char	*ft_makestr(const char *buffer, char c)
{
	char		*line;
	char		*rmd;
	static char	*remainder;
	int			size;

	if (c == '\0')
		return (ft_lastline(remainder));
	buffer = ft_strjoin(remainder, buffer);
	rmd = ft_strchr(buffer, c);
	free(remainder);
	if (!rmd)
	{
		remainder = ft_calloc(ft_strlen(buffer), sizeof(char));
		ft_strlcpy(remainder, buffer, ft_strlen(buffer));
		return (NULL);
	}
	remainder = ft_calloc((ft_strlen(rmd) + 1), sizeof(char));
	ft_strlcpy(remainder, rmd, sizeof(rmd));
	size = ((ft_strlen(buffer)) - (ft_strlen(remainder)));
	line = ft_calloc(size, sizeof(char *));
	ft_strlcpy(line, buffer, size);
	return (line);
}

char	*ft_lastline(char *remainder)
{
	char	*line;

	line = ft_calloc(ft_strlen((const char *)remainder), sizeof(char));
	ft_strlcpy(line, (const char *)remainder, ft_strlen((const char *)remainder));
	free(remainder);
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
	if (size != 0 && nmemb > size_t_max / size)
		return (NULL);
	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
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
