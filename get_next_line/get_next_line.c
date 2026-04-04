/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harramar <harramar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:19:00 by harramar          #+#    #+#             */
/*   Updated: 2026/04/02 08:02:57 by harramar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_stash(char *stash)
{
	char	*new_stash;
	int		i;
	int		j;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	new_stash = malloc(sizeof(char) * (ft_strlen1(stash) - i + 1));
	if (!new_stash)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	if (new_stash && *new_stash == '\0')
		return (free(new_stash), NULL);
	return (new_stash);
}

char	*extract_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash || !stash[0])
		return (NULL);
	line = malloc(sizeof(char) * (ft_strlen1(stash) + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] && stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read(int fd, char *stash)
{
	char	*buffer;
	ssize_t	v_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	v_read = 1;
	while (v_read > 0 && !ft_strchr1(stash, '\n'))
	{
		v_read = read(fd, buffer, BUFFER_SIZE);
		if (v_read < 0)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		if (v_read == 0)
			break ;
		buffer[v_read] = '\0';
		stash = ft_strjoin1(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read(fd, stash);
	line = extract_line(stash);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	stash = update_stash(stash);
	return (line);
}
