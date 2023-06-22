/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:11:54 by stopcic           #+#    #+#             */
/*   Updated: 2022/10/14 13:06:23 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (big == NULL && len == 0)
		return (0);
	if ((ft_strlen(big) == 0 && ft_strlen(little) == 0)
		|| ft_strlen(little) == 0)
		return ((char *)big);
	if (ft_strlen(big) == 0)
		return (0);
	j = 0;
	while (len != 0 && *big && j < len)
	{
		if (*big == *little)
		{
			i = 1;
			while (little[i] == big[i] && little[i] && j + i < len)
				i++;
			if (little[i] == '\0')
				return ((char *)big);
		}
		big++;
		j++;
	}
	return (NULL);
}
