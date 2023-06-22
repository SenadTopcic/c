/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <stopcic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:53:04 by stopcic           #+#    #+#             */
/*   Updated: 2023/04/02 10:03:38 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_parts(const char *s, char delimiter)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		if (s[i] == delimiter)
			i++;
		else if (s[i] != delimiter && (s[i +1] == delimiter || s[i +1] == '\0'))
		{
			counter++;
			i++;
		}
		else
			i++;
	}
	return (counter);
}

static char	*cut_part(const char *s, int start, int end_of_part)
{
	char	*part;
	int		i;

	i = 0;
	part = malloc((end_of_part - start + 1) * sizeof(char));
	if (!part)
		return (NULL);
	while (start < end_of_part)
		part[i++] = s[start++];
	part[i] = '\0';
	return (part);
}

static void	add_to_result(char **result, const char *s, char c, int index)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i <= (size_t)ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == (size_t)ft_strlen(s)) && index >= 0)
		{
			result[j++] = cut_part(s, index, i);
			index = -1;
		}
		i++;
	}
	result[j] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		index;

	if (!s)
		return (NULL);
	result = malloc((count_parts(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	index = -1;
	add_to_result(result, s, c, index);
	return (result);
}
