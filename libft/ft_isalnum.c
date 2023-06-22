/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:21:35 by stopcic           #+#    #+#             */
/*   Updated: 2022/10/06 11:29:46 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	result;

	result = 0;
	if (((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'))
		|| (c >= 'A' && c <= 'Z'))
		result = 1;
	return (result);
}