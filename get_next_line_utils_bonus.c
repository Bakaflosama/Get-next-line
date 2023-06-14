/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flweynan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:05:54 by flweynan          #+#    #+#             */
/*   Updated: 2023/06/13 09:52:25 by flweynan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char	*str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *stash, char *buf)
{
	char	*dst;
	int		i;
	int		j;

	if (!stash)
	{
		stash = (char *)malloc(1 * sizeof(char));
		stash[0] = '\0';
	}
	if (!stash || !buf)
		return (NULL);
	dst = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buf) + 1));
	if (dst == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (stash)
		while (stash[++i] != '\0')
			dst[i] = stash[i];
	while (buf[j] != '\0')
		dst[i++] = buf[j++];
	dst[ft_strlen(stash) + ft_strlen(buf)] = '\0';
	free(stash);
	return (dst);
}

char	*ft_stash_to_line(char *stash)
{
	int		i;
	char	*dst;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	dst = (char *)malloc(sizeof(char) * (i + 2));
	if (!dst)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		dst[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		dst[i] = stash[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_remove_line(char *stash)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	dst = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!dst)
		return (NULL);
	i++;
	j = 0;
	while (stash[i] != '\0')
		dst[j++] = stash[i++];
	dst[j] = '\0';
	free(stash);
	return (dst);
}
