/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utilis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <stopcic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:20:42 by stopcic           #+#    #+#             */
/*   Updated: 2023/03/28 16:46:09 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n *= -1;
			ft_putchar('-');
		}
		if (n < 10)
			ft_putchar(n + '0');
		else
		{
			ft_putnbr((n / 10));
			ft_putchar((n % 10) + '0');
		}
	}
}

int	ft_atoi(const char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = sign * (-1);
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (res > 2147483647 / 10 && *str - '0' > 7)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		else
			res = res * 10 + *str++ - '0';
	}
	return ((int)(res * sign));
}
