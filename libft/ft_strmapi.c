/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:01:35 by stopcic           #+#    #+#             */
/*   Updated: 2022/10/23 15:51:19 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned long	i;
	unsigned long	length_s;
	char			*result;

	length_s = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (length_s + 1));
	if (result == 0)
		return (result);
	i = 0;
	while (i < length_s)
	{
		result[i] = (*f)(i, s[i]);
		++i;
	}
	result[i] = 0;
	return (result);
}
