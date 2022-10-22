/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:14:47 by ckunimur          #+#    #+#             */
/*   Updated: 2022/10/22 17:31:52 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	size_t	reader;
	char	*buffer;

	line = NULL;
	buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	if (fd >= 0 && BUFFER_SIZE > 0)
	{
		reader = BUFFER_SIZE;
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		line = ft_take_next_line(fd, buffer, reader);
		free (buffer);
		return (line);
	}
	return (NULL);
}

char	*ft_take_next_line(int fd, char *buffer, size_t reader)
{
	char		*rmd;
	static char	*remainder;
	char		*line;
	size_t		len;

	while (reader > 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		buffer[reader] = '\0';
		rmd = ft_strchr(buffer, '\n');
		if (!rmd && reader > 0)
			remainder = ft_strjoin(remainder, buffer);
		if (rmd)
		{
			len = (ft_strlen(buffer) - ft_strlen(rmd));
			line = ft_makestr(&remainder, buffer, len);
			remainder = ft_strdup(rmd);
			reader = 1;
			return (line);
		}
	}
	if (reader == 0 && &remainder[0] != 0)
		return (ft_finish(&remainder));
	return (NULL);
}

char	*ft_makestr(char **remainder, char *buffer, size_t len)
{
	char	*line;
	char	*nextline;

	line = buffer;
	if (*remainder || buffer)
	{
		nextline = ft_substr(line, 0, len);
		line = ft_strjoin(*remainder, nextline);
		free(nextline);
	}
	return(line);
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

char	*ft_finish(char **remainder)
{
	char	*line;

	if (**remainder == '\0')
	{
		free (*remainder);
		*remainder = NULL;
		return (NULL);
	}
	line = ft_strdup(*remainder);
	free (*remainder);
	*remainder = NULL;
	return (line);
}
