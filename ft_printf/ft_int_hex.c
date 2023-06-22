/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:13:05 by stopcic           #+#    #+#             */
/*   Updated: 2022/11/07 19:32:30 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>
#include "ft_printf.h"

static void	add_hex(char *result, unsigned long long int c, char hex, int len);
static int	num_of_hx_digit(unsigned long long int c);

int	ft_int_hex(unsigned long long int c, char hex)
{
	char	*result;
	int		hex_str_len;
	int		len;
	int		counter;

	counter = 0;
	hex_str_len = num_of_hx_digit(c);
	len = hex_str_len - 1;
	result = (char *)malloc(sizeof(char) * (hex_str_len + 1));
	if (!result)
		return (0);
	add_hex(result, c, hex, len);
	counter = ft_putstr_pf(result);
	free (result);
	return (counter);
}

//add hex to result
static void	add_hex(char *result, unsigned long long int c, char hex, int len)
{
	int	remainder;
	int	condition;
	int	kraj;

	kraj = len + 1;
	remainder = -1;
	condition = 1;
	while (condition)
	{
		remainder = (c % 16);
		c = c / 16;
		if (remainder < 16)
		{
			if (remainder <= 9)
				result[len] = remainder + '0';
			else if (remainder >= 10 && remainder < 16)
				result[len] = (remainder - 10) + (hex - 23);
		}
		if (c == 0)
			condition = 0;
		len--;
	}
	result[kraj] = '\0';
}

//size of hex
static int	num_of_hx_digit( unsigned long long int c)
{
	int	cnt;

	cnt = 0;
	if (c == 0)
		return (1);
	else
	{
		while (c > 0)
		{
			c = c / 16;
			cnt++;
		}
		return (cnt);
	}
}
/*
int	main(void)
{
	printf("    %s\n", ft_int_hex(32345340, 'X'));
	printf("    %X\n", 32345340);
	return (0);
}*/
