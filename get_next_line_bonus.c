/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsyvasal <bsyvasal@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:39:02 by bsyvasal          #+#    #+#             */
/*   Updated: 2023/11/03 09:53:31 by bsyvasal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_line(int fd)
{
	char	*buffer;
	char	*res;
	int		bytes;

	buffer = malloc (BUFFER_SIZE);
	if (!buffer)
		return (0);
	res = NULL;
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0 || !*buffer)
			break ;
		buffer[bytes] = 0;
		res = ft_strjoin(res, buffer);
		if (ft_strchr(res, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

static char	*cache_get_line(char *cache)
{
	int	i;

	i = 0;
	if (!*cache)
		return (0);
	while (cache[i] && cache[i] != '\n')
		i++;
	return (ft_substr(cache, 0, i + 1));
}

static char	*trim_cache(char *cache)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (cache[i] && cache[i] != '\n')
		i++;
	if (cache[i] == '\n')
		i++;
	tmp = ft_substr(cache, i, ft_strlen(cache) - 1);
	free(cache);
	if (!*tmp)
	{
		free(tmp);
		return (NULL);
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*cache[1024];
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!(cache[fd] && ft_strchr(cache[fd], '\n')))
	{
		buffer = read_line(fd);
		if (buffer)
		{
			cache[fd] = ft_strjoin(cache[fd], buffer);
			free(buffer);
		}
	}
	if (cache[fd])
	{
		buffer = cache_get_line(cache[fd]);
		cache[fd] = trim_cache(cache[fd]);
		return (buffer);
	}
	return (0);
}
