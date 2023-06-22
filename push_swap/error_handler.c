/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <stopcic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 10:11:03 by stopcic           #+#    #+#             */
/*   Updated: 2023/04/07 10:55:20 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//return error if character is not a number
int	ft_is_a_number(char *user_input)
{
	int	i;

	i = 0;
	if ((user_input[i] == '-' || user_input[i] == '+')
		&& (user_input[i + 1] >= 48 && user_input[i + 1] <= 57))
		i++;
	while (user_input[i] != '\0')
	{
		if (!(user_input[i] >= 48 && user_input[i] <= 57))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

//return error if number is not in rage of MAX and MIN value of integer
int	ft_is_a_number_in_range(char *user_input)
{
	long long	num;

	num = ft_atoll(user_input);
	if (num <= (long long)MAXNUM && num >= (long long)MINNUM)
	{
		return (1);
	}
	write(1, &"Error\n", 6);
	return (0);
}

// fill array with numbers and check if those numbers are unique( return 0)
// otherwise print error and  return 1
int	ft_is_a_number_duplicated(int *stack_arr, char **user_input, int size)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	while (i < size)
	{
		stack_arr[i] = ft_atoll(user_input[i]);
		i++;
	}
	i = 0;
	while (i < size)
	{
		num = stack_arr[i];
		j = i + 1;
		while (j < size)
		{
			if (num == stack_arr[j])
				return (write(1, &"Error\n", 6));
			j++;
		}
		i++;
	}	
	return (0);
}
