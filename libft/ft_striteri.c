/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 09:40:48 by stopcic           #+#    #+#             */
/*   Updated: 2022/10/24 09:59:41 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	length_s;
	size_t	i;

	i = 0;
	length_s = ft_strlen(s);
	while (i < length_s)
	{
		f(i, (s + i));
		i++;
	}
}
