/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_pf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:59:18 by stopcic           #+#    #+#             */
/*   Updated: 2022/11/08 11:00:03 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	positive_number(int n)
{
	int	cond;

	cond = 0;
	if (n == 0)
		return (1);
	else
	{
		while (n > 0)
		{
			n = n / 10;
			cond++;
		}
		return (cond);
	}
}

static int	nmb_of_digt(int n)
{
	if (n >= 0)
		return (positive_number(n));
	else if (n == -2147483648)
		return (10);
	else
		return (positive_number((-1 * n)));
}

static void	add_number(char *result, int n, int dp_length)
{
	unsigned int	num;
	int				c_int;
	int				t_len;

	if (n >= 0)
	{
		num = n;
		t_len = dp_length;
	}
	else
	{
		num = n * (-1);
		t_len = dp_length + 1;
	}
	while (t_len--)
	{
		c_int = num % 10;
		result[t_len] = c_int + '0';
		num = num / 10;
	}
}

int	ft_itoa_pf(int n)
{
	char	*result;
	int		dp_length;
	int		end_str;

	dp_length = nmb_of_digt(n);
	if (n >= 0)
		result = malloc(sizeof(char) * (dp_length + 1));
	else
		result = malloc(sizeof(char) * (dp_length + 2));
	if (!result)
		return (0);
	end_str = dp_length + 1;
	if (n >= 0)
		add_number(result, n, dp_length);
	else if (n < 0)
	{
		end_str = dp_length + 2;
		add_number(result, n, dp_length);
		result[0] = '-';
	}
	result[end_str - 1] = '\0';
	end_str = ft_putstr_pf(result);
	free (result);
	return (end_str);
}
/*
int main()
{
	//int i = nmb_of_digt(-1239);
	//printf("%d\n", i);
	char *rez = ft_itoa_pf(1239);
	printf("%s\n", rez);
	char *res = ft_itoa_pf(-1049292875);
   	printf("|%s|", res);

}*/
