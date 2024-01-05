/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:12:42 by merdal            #+#    #+#             */
/*   Updated: 2024/01/05 16:29:29 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*text = NULL;
	char		*returnline;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
	{
		free(text);
		text = NULL;
		return (NULL);
	}
	text = readtext(fd, text);
	if (text == NULL)
		return (NULL);
	returnline = countlen(text);
	temp = readline(text);
	free(text);
	if (!temp)
		text = NULL;
	text = temp;
	return (returnline);
}

char	*readtext(int fd, char *text)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && ft_strchr(text, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		text = ft_strjoin(text, buffer);
	}
	free(buffer);
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
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!buffer || !buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (NULL);
	nextline = (char *)malloc((ft_strlen(buffer + i + 1) + 1) * sizeof(char));
	if (!nextline)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		nextline[j++] = buffer[i++];
	nextline[j] = '\0';
	return (nextline);
}
