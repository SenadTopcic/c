/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <stopcic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:03:36 by stopcic           #+#    #+#             */
/*   Updated: 2023/04/05 21:51:31 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			return ((char *)(s));
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)(s));
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;
	int		leng_s;

	leng_s = (int)(ft_strlen(s));
	i = 0;
	ptr = malloc(sizeof(char) * leng_s + 1);
	if (ptr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	j;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("\0");
	else
	{
		while (s1[i])
			result[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		result[j++] = s2[i++];
	}
	result[j] = '\0';
	return (result);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	a;

	if (s)
	{
		if (start >= ft_strlen(s))
			return (ft_strdup(""));
		if (ft_strlen(s) > len)
			subs = (char *)malloc(sizeof(char) * (len + 1));
		if (ft_strlen(s) <= len)
			subs = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
		if (!subs)
			return (NULL);
		a = 0;
		while (a < len && s[start + a] != '\0')
		{
			subs[a] = s[start + a];
			a++;
		}
		subs[a] = '\0';
		return (subs);
	}
	return (0);
}
