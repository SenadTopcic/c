/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:56:53 by stopcic           #+#    #+#             */
/*   Updated: 2022/10/14 17:49:34 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_substr(size_t len, char *str_f, char const *s,
		unsigned int start)
{
	size_t	i;	

	i = 0;
	while (len-- && (ft_strlen(s) - start) > 0)
	{
		str_f[i] = (char)s[start];
		start++;
		i++;
	}
	str_f[i] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s)
	{
		if (start >= ft_strlen(s))
			return (ft_strdup(""));
		if (ft_strlen(s) > len)
			str = (char *)malloc(sizeof(char) * len + 1);
		else
			str = (char *)malloc(sizeof(char) * ft_strlen(s) - start + 1);
		if (str == NULL)
			return (NULL);
		else
			if (ft_strlen(s) > start)
				copy_substr(len, str, s, start);
		return (str);
	}
	else
		return (0);
}
