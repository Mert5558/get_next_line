/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:12:42 by merdal            #+#    #+#             */
/*   Updated: 2024/01/10 13:56:10 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*text[OPEN_MAX];
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
	{
		free(text[fd]);
		text[fd] = NULL;
		return (NULL);
	}
	text[fd] = readtext(fd, text[fd]);
	if (text[fd] == NULL)
		return (NULL);
	line = countlen(text[fd]);
	temp = readline(text[fd]);
	free(text[fd]);
	if (!temp)
		text[fd] = NULL;
	text[fd] = temp;
	return (line);
}

char	*readtext(int fd, char *text)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytesread;

	bytesread = 1;
	while (bytesread > 0 && !ft_strchr(text, '\n'))
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
		{
			free(text);
			return (NULL);
		}
		if (bytesread > 0)
		{
			buffer[bytesread] = '\0';
			text = ft_strjoin(text, buffer);
		}
	}
	return (text);
}

char	*countlen(char *text)
{
	char	*singleline;
	size_t	length;
	size_t	i;

	if (text == NULL || *text == '\0')
		return (NULL);
	length = 0;
	while (text[length] != '\n' && text[length] != '\0')
		length++;
	singleline = malloc(length + 2);
	if (singleline == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		singleline[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
	{
		singleline[i] = text[i];
		i++;
	}
	singleline[i] = '\0';
	return (singleline);
}

char	*readline(char *buffer)
{
	char	*nextline;
	char	*newlinepos;
	size_t	i;
	size_t	len;

	if (!buffer || !*buffer)
		return (NULL);
	nextline = NULL;
	newlinepos = ft_strchr(buffer, '\n');
	if (!newlinepos || !newlinepos[1])
		return (NULL);
	len = ft_strlen(newlinepos + 1);
	nextline = malloc((len + 1) * sizeof(char));
	if (!nextline)
		return (NULL);
	i = 0;
	while (newlinepos[i + 1])
	{
		nextline[i] = newlinepos[i + 1];
		i++;
	}
	nextline[i] = '\0';
	return (nextline);
}
