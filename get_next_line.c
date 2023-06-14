/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flweynan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:01:50 by flweynan          #+#    #+#             */
/*   Updated: 2023/06/13 09:19:55 by flweynan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_to_stash(int fd, char *stash)
{
	char	*buff;
	int		read_return;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	read_return = 1;
	while (!ft_strchr(stash, '\n') && read_return != 0)
	{
		read_return = read(fd, buff, BUFFER_SIZE);
		if (read_return == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_return] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		if (stash)
			*stash = 0;
		return (NULL);
	}
	stash = ft_read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_stash_to_line(stash);
	stash = ft_remove_line(stash);
	return (line);
}
