/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_p_swap_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <stopcic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:44:47 by stopcic           #+#    #+#             */
/*   Updated: 2023/04/04 12:24:37 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one
*/
void	ra(t_push_swap *ps)
{
	int	i;
	int	tmp_int;

	i = 0;
	tmp_int = ps->stack_a[0];
	while (i < ps->num_el_in_stack_a)
	{
		ps->stack_a[i] = ps->stack_a[i + 1];
		i++;
	}
	ps->stack_a[i - 1] = tmp_int;
	write(1, &"ra\n", 3);
}

/*
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one
*/
void	rb(t_push_swap *ps)
{
	int	i;
	int	tmp_int;

	i = 0;
	tmp_int = ps->stack_b[0];
	while (i < ps->num_el_in_stack_b)
	{
		ps->stack_b[i] = ps->stack_b[i + 1];
		i++;
	}
	ps->stack_b[i - 1] = tmp_int;
	write(1, &"rb\n", 3);
}

/*
rr : ra and rb at the same time
*/
void	rr(t_push_swap *ps)
{
	int	i;
	int	tmp_int;

	i = 0;
	tmp_int = ps->stack_a[0];
	while (i < ps->num_el_in_stack_a)
	{
		ps->stack_a[i] = ps->stack_a[i + 1];
		i++;
	}
	ps->stack_a[i - 1] = tmp_int;
	i = 0;
	tmp_int = ps->stack_b[0];
	while (i < ps->num_el_in_stack_b)
	{
		ps->stack_b[i] = ps->stack_b[i + 1];
		i++;
	}
	ps->stack_b[i - 1] = tmp_int;
	write(1, &"rr\n", 3);
}

/*
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one
*/
void	rra(t_push_swap *ps)
{
	int	i;
	int	tmp_int;

	i = ps->num_el_in_stack_a - 1;
	tmp_int = ps->stack_a[ps->num_el_in_stack_a - 1];
	while (i > 0)
	{
		ps->stack_a[i] = ps->stack_a[i - 1];
		i--;
	}
	ps->stack_a[0] = tmp_int;
	write(1, &"rra\n", 4);
}

/*
 rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
 */
void	rrb(t_push_swap *ps)
{
	int	i;
	int	tmp_int;

	i = ps->max_size - 1;
	tmp_int = ps->stack_b[ps->max_size - 1];
	while (i > 0)
	{
		ps->stack_b[i] = ps->stack_b[i - 1];
		i--;
	}
	ps->stack_b[0] = tmp_int;
	write(1, &"rrb\n", 3);
}
