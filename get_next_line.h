/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:14:50 by ckunimur          #+#    #+#             */
/*   Updated: 2022/10/14 17:42:57 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// functions 

char	*get_next_line(int fd);
char	*ft_strchr(const char *p, char c);
char	*takenextline(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_ifchr(int len, char *p, char c);
char	*ft_makestr(const char *buffer, char c);
char	*ft_lastline(char *p);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
