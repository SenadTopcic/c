/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <stopcic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:18:18 by stopcic           #+#    #+#             */
/*   Updated: 2023/04/06 15:34:09 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//pb_i (push b): Take the first element at the top of
//i_a and put it at the top of i_b.
//Do nothing if _a_i is empty.
void	pb_i(t_push_swap *ps)
{
	long int	i;

	if (ps->size_index_a != 0)
	{
		i = ps->size_index_b + 1;
		while (i > 0)
		{
			ps->index_b[i] = ps->index_b[i - 1];
			i--;
		}
		ps->size_index_b++;
		ps->index_b[0] = ps->index_arr[0];
		i = 0;
		while (i < ps->size_index_a)
		{
			ps->index_arr[i] = ps->index_arr[i + 1];
			i++;
		}
		ps->size_index_a--;
	}
}

//pa (push a_i): Take the first element at the top of b_i and put
// it at the top of a.
//Do nothing if b_i is empty.
void	pa_i(t_push_swap *ps)
{
	int	i;

	if (ps->size_index_b != 0)
	{
		i = ps->size_index_a + 1;
		while (i > 0)
		{
			ps->index_arr[i] = ps->index_arr[i - 1];
			i--;
		}
		ps->size_index_a++;
		ps->index_arr[0] = ps->index_b[0];
		i = 0;
		while (i < ps->size_index_b)
		{
			ps->index_b[i] = ps->index_b[i + 1];
			i++;
		}
		ps->size_index_b--;
	}
}

/*
ra_ (rotate a_i): Shift up all elements of stack a by 1.
The first element becomes the last one
*/
void	ra_i(t_push_swap *ps)
{
	int	i;
	int	tmp_int;

	i = 0;
	tmp_int = ps->index_arr[0];
	while (i < ps->size_index_a)
	{
		ps->index_arr[i] = ps->index_arr[i + 1];
		i++;
	}
	ps->index_arr[i - 1] = tmp_int;
}

/*
rb_i (rotate b_I): Shift up all elements of stack b by 1.
The first element becomes the last one
*/
void	rb_i(t_push_swap *ps)
{
	int	i;
	int	tmp_int;

	i = 0;
	tmp_int = ps->index_b[0];
	while (i < ps->size_index_b)
	{
		ps->index_b[i] = ps->index_b[i + 1];
		i++;
	}
	ps->index_b[i - 1] = tmp_int;
}
