/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <stopcic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:15:29 by stopcic           #+#    #+#             */
/*   Updated: 2023/04/07 10:54:00 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_sort_stack_b(t_push_swap *ps, int b_size, int bit_size, int j)
{
	while (b_size-- && j <= bit_size)
	{
		if (((ps->index_b[0] >> j) & 1) == 0)
		{
			rb(ps);
			rb_i(ps);
		}
		else
		{
			pa_i(ps);
			pa(ps);
		}
	}
}

void	radix_sort(t_push_swap *ps)
{
	int	bit_size;
	int	size;

	bit_size = 0;
	size = ps->size_index_a;
	while (size > 1 && ++bit_size)
		size /= 2;
	do_moves_in_radix(size, bit_size, ps);
	while (ps->size_index_b != 0)
	{
		pa_i(ps);
		pa(ps);
	}
}

void	do_moves_in_radix(int size, int bit_size, t_push_swap *ps)
{
	int	j;

	j = -1;
	while (++j <= bit_size)
	{
		size = ps->size_index_a;
		while (size-- && !check_is_sorted_index(ps))
		{
			if (((ps->index_arr[0] >> j) & 1) == 0)
			{
				pb_i(ps);
				pb(ps);
			}
			else
			{
				ra_i(ps);
				ra(ps);
			}
		}
		radix_sort_stack_b(ps, ps->size_index_b, bit_size, j + 1);
	}
}

//check is array sorted
int	check_is_sorted_index(t_push_swap *ps)
{
	int	iterator;
	int	result;

	result = 1;
	iterator = 0;
	while (iterator < ps->size_index_a - 1)
	{
		if (ps->index_arr[iterator] > ps->index_arr[iterator + 1])
			result = 0;
		iterator++;
	}
	iterator = 0;
	while (iterator < ps->size_index_b - 1)
	{
		if (ps->index_b[iterator] > ps->index_b[iterator + 1])
			result = 0;
		iterator++;
	}
	return (result);
}

//function check is smallest number in array
int	is_smallest_number(t_push_swap *ps, int position)
{
	int	i;

	i = 0;
	while (i < ps->num_el_in_stack_a)
	{
		if ((ps->stack_a[position] > ps->stack_a[i]))
			return (0);
		i++;
	}
	return (1);
}
