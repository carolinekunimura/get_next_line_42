/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:14:37 by ckunimur          #+#    #+#             */
/*   Updated: 2022/10/14 17:42:22 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*p;
	size_t	size_len;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	size_len = ft_strlen((char *)s1) + ft_strlen ((char *)s2);
	p = ft_calloc((size_len + 1), (sizeof(char)));
	while (i < size_len)
	{
		if (i < ft_strlen((char *)s1))
			p[i] = s1[i];
		if (i >= ft_strlen((char *)s1))
		{
			p[i] = s2[j];
			j++;
		}
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strchr(const char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *) &s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

int	ft_ifchr(int len, char *p, char c)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (p[i] == c)
			return (1);
	}
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		return (ft_strlen(src));
	}
	else
	{
		while (i < (size - 1) && i < (ft_strlen(src)))
		{
			dst[i] = ((char *)src)[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
