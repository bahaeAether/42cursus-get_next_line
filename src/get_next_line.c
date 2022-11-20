/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 21:19:22 by baboulou          #+#    #+#             */
/*   Updated: 2022/11/18 03:53:50 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_read(char *buffer, int fd)
{
	char	*holder;
	ssize_t	n;

	holder = malloc(BUFFER_SIZE + 1);
	if (!holder)
	{
		free(buffer);
		return (0);
	}
	holder[0] = 0;
	n = 1;
	while (!ft_strchr(buffer, '\n') && n != 0)
	{
		n = read(fd, holder, BUFFER_SIZE);
		if (n == -1)
		{
			free(holder);
			free(buffer);
			return (0);
		}
		buffer = ft_strjoin(buffer, holder, n);
	}
	free(holder);
	return (buffer);
}

char	*ft_get_line(char *buffer)
{
	int		i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		return (ft_substr(buffer, 0, i + 1));
	else
		return (ft_substr(buffer, 0, i));
}

char	*ft_update(char *buffer)
{
	char	*holder;
	int		i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	holder = ft_substr(buffer, i + 1, SIZE_MAX);
	free(buffer);
	return (holder);
}

char	*get_next_line(int fd)
{
	char		*holder;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_read(buffer, fd);
	if (!buffer)
		return (0);
	holder = ft_get_line(buffer);
	buffer = ft_update(buffer);
	if (holder && holder[0] == '\0')
	{
		free(buffer);
		free(holder);
		return (0);
	}
	return (holder);
}
