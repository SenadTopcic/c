/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_p_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <stopcic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:44:47 by stopcic           #+#    #+#             */
/*   Updated: 2023/04/07 10:17:51 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_alg(t_push_swap *ps)
{
	make_index(ps);
	if (!check_is_sorted(ps))
	{
		if (ps->max_size == 2)
			sa(ps);
		else if (ps->max_size == 3)
			hard_code_me_3(ps);
		else if (ps->max_size == 4)
			hard_code_me_4(ps);
		else if (ps->max_size == 5)
			hard_code_me_5(ps);
		else
		{
			radix_sort(ps);
		}
	}
}

//check is array sorted
int	check_is_sorted(t_push_swap *ps)
{
	int	iterator;
	int	result;

	result = 1;
	iterator = 0;
	while (iterator < ps->num_el_in_stack_a - 1)
	{
		if (ps->stack_a[iterator] > ps->stack_a[iterator + 1])
			result = 0;
		iterator++;
	}
	while (iterator < ps->num_el_in_stack_b - 1)
	{
		if (ps->stack_b[iterator] > ps->stack_b[iterator + 1])
			result = 0;
		iterator++;
	}
	return (result);
}

//make index array of stack_a
void	make_index(t_push_swap *ps)
{
	int			i;
	int			j;
	int			k;
	long int	min;

	i = ps->max_size;
	while (i--)
		ps->new_arr[i] = ps->stack_a[i];
	i = 0;
	while (i < ps->max_size)
	{
		j = 0;
		min = (long int)MAXNUM + (long int)1;
		while (j < ps->max_size)
		{
			if (ps->new_arr[j++] < min)
			{
				min = ps->new_arr[j - 1];
				k = j - 1;
			}
		}
		ps->new_arr[k] = (long int)MAXNUM + (long int)1;
		ps->index_arr[k] = i++;
	}
}
