/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:32:06 by stopcic           #+#    #+#             */
/*   Updated: 2022/10/16 20:49:09 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first_occurence;
	size_t	last_occurence;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	first_occurence = 0;
	while (s1[first_occurence] != '\0' && ft_strchr(set, s1[first_occurence]))
		first_occurence++;
	last_occurence = ft_strlen(s1);
	while (ft_strchr(set, s1[last_occurence]))
		last_occurence--;
	end = last_occurence - first_occurence;
	return (ft_substr(s1, first_occurence, end + 1));
}
