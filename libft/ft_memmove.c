/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:14:09 by stopcic           #+#    #+#             */
/*   Updated: 2022/10/11 12:25:33 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest_char;
	char	*src_char;

	dest_char = (char *)dest;
	src_char = (char *)src;
	if (src < dest)
	{
		src_char = src_char + n - 1;
		dest_char = dest_char + n - 1;
		while (n--)
			*(dest_char--) = *src_char--;
	}
	else if (src > dest)
	{
		while (n--)
			*dest_char++ = *src_char++;
	}
	return (dest);
}
