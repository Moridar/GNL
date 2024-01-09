/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsyvasal <bsyvasal@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:31:16 by bsyvasal          #+#    #+#             */
/*   Updated: 2023/11/27 13:41:24 by bsyvasal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	strlen;

	if (!s)
		return (NULL);
	strlen = ft_strlen(s) - start;
	if (strlen < len)
		len = strlen;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[0] = 0;
	if (start >= ft_strlen(s))
		return (str);
	ft_memcpy(str, s + start, len);
	str[len] = 0;
	return (str);
}

size_t	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (*(s++))
		i++;
	return (i);
}

char	*ft_strjoin_and_free(char *s1, char *s2)
{
	char	*str;
	int		s1len;
	int		s2len;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_substr(s2, 0, ft_strlen(s2)));
	if (!s2)
	{
		free(s1);
		return (ft_substr(s1, 0, ft_strlen(s1)));
	}
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = malloc (s1len + s2len + 1);
	if (str)
	{
		ft_memcpy(str, s1, s1len);
		ft_memcpy(str + s1len, s2, s2len + 1);
	}
	free(s1);
	return (str);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *) s;
	while (*ptr)
	{
		if (*ptr == (char) c)
			return (ptr);
		ptr++;
	}
	if ((char) c == 0)
		return (ptr);
	return (NULL);
}
