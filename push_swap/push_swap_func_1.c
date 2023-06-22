/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_func_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <stopcic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 10:16:53 by stopcic           #+#    #+#             */
/*   Updated: 2023/04/03 21:37:31 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//custom made  ascii to long long integer
long long	ft_atoll(const char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = sign * (-1);
		str++;
	}
	if (*str == '+')
	{
		str++;
	}
	while (*str)
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * sign);
}

//return size of 2D array as a int
int	two_d_arr_len(char **arr)
{
	int	counter;

	counter = 0;
	while (*arr++)
	{
		counter++;
	}
	return (counter);
}

//return total number of characters in 2d array
int	give_me_size(char **arr, int counter)
{
	int	length;
	int	iterator;

	length = 0;
	iterator = 0;
	while (counter >= 1)
	{
		iterator = 0;
		while (arr[counter][iterator] != '\0')
		{
			length++;
			iterator++;
		}
		length++;
		counter--;
	}
	return (length);
}

//return string from 2d array
char	*make_me_string(char **arr, int size, int counter)
{
	char	*result_str;
	int		iterator_result;
	int		inner_counter;
	int		ac_counter;

	ac_counter = 1;
	iterator_result = 0;
	inner_counter = -1;
	result_str = malloc(sizeof(char) * (size + 1));
	if (!result_str)
		return (NULL);
	while (counter >= 1)
	{
		inner_counter = -1;
		size = ft_strlen(arr[ac_counter]);
		while (++inner_counter < size)
			result_str[iterator_result++] = arr[ac_counter][inner_counter];
		result_str[iterator_result] = ' ';
		iterator_result++;
		ac_counter++;
		counter--;
	}
	result_str[iterator_result] = '\0';
	return (result_str);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
