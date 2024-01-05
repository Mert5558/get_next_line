/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:14:45 by merdal            #+#    #+#             */
/*   Updated: 2024/01/05 16:35:45 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		len;

	len = 0;
	if (s == NULL)
		return (NULL);
	while (s[len] != (char)c)
	{
		if (s[len] == '\0')
			return (0);
		len++;
	}
	return ((char *)s + len);
}
//fix join
char	*ft_strjoin(char *s1, char *s2)
{
	char	*con_str;
	size_t	j;
	size_t	i;

	if (s1 == NULL)
		s1 = ft_strempty(s1);
	if (s2 == NULL)
		return (NULL);
	con_str = malloc (sizeof(char) * (ft_strlen (s1) + ft_strlen (s2) + 1));
	if (con_str == NULL)
	{
		free (s1);
		return (NULL);
	}
	j = 0;
	i = 0;
	while (s1[j] != '\0')
		con_str[i++] = s1[j++];
	j = 0;
	free (s1);
	while (s2[j] != '\0')
		con_str[i++] = s2[j++];
	con_str[i] = '\0';
	return (con_str);
}

size_t	ft_strlen(const char *str)
{
	int	l;

	l = 0;
	while (*str != '\0')
	{
		l++;
		str++;
	}
	return (l);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_d;
	size_t	i;

	len_d = 0;
	i = 0;
	len_d = ft_strlen(dest);
	if (size == 0 || len_d > size)
		return (size + ft_strlen(src));
	while (src[i] != '\0' && len_d + 1 < size)
	{
		dest[len_d] = src[i];
		len_d++;
		i++;
	}
	dest[len_d] = '\0';
	return (ft_strlen(dest) + ft_strlen(src + i));
}

char	*ft_strempty(char *str)
{
	str = malloc(1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	else
		str[0] = '\0';
	return (str);
}