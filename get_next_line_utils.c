/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 01:09:33 by baboulou          #+#    #+#             */
/*   Updated: 2022/11/18 02:38:26 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	if (!dst || !src)
		return (0);
	i = ft_strlen(dst);
	if (dstsize <= i)
		return (ft_strlen(src) + dstsize);
	j = 0;
	while (src[j] && i + j + 1 < dstsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (ft_strlen(src) + i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	while (src[i] && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;

	if (start >= ft_strlen(s))
		return (0);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}

char	*ft_strjoin(char *s1, char *s2, int n)
{
	char	*result;

	s2[n] = '\0';
	if (!s1)
	{
		result = malloc(ft_strlen(s2) + 1);
		if (!result)
			return (0);
		ft_strlcpy(result, s2, ft_strlen(s2) + 1);
		return (result);
	}
	if (s2[0] == '\0')
		return (s1);
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(result, s1, ft_strlen(s1) + 1);
	ft_strlcat(result, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	free(s1);
	return (result);
}

int	ft_strchr(char *s, int c)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return (1);
		i++;
	}
	return (0);
}
