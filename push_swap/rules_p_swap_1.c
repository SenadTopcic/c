/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_p_swap_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <stopcic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:44:47 by stopcic           #+#    #+#             */
/*   Updated: 2023/04/06 15:39:44 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements
*/
void	sa(t_push_swap *ps)
{
	int	i;
	int	tmp_num;

	if (!check_is_sorted(ps))
	{
		if (ps->num_el_in_stack_a > 1)
		{
			i = 0;
			tmp_num = ps->stack_a[i];
			ps->stack_a[i] = ps->stack_a[i + 1];
			ps->stack_a[i + 1] = tmp_num;
			write(1, &"sa\n", 3);
		}
	}
}

/*
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
*/
void	sb(t_push_swap *ps)
{
	int	i;
	int	tmp_num;

	if (!check_is_sorted(ps))
	{
		if (ps->num_el_in_stack_b > 1)
		{
			i = 0;
			tmp_num = ps->stack_b[i];
			ps->stack_b[i] = ps->stack_b[i + 1];
			ps->stack_b[i + 1] = tmp_num;
			write(1, &"sb\n", 3);
		}
	}
}

//ss : sa and sb at the same time.
void	ss(t_push_swap *ps)
{
	int	i;
	int	tmp_num;

	if (!check_is_sorted(ps))
	{
		if (ps->num_el_in_stack_a > 1)
		{
			i = 0;
			tmp_num = ps->stack_a[i];
			ps->stack_a[i] = ps->stack_a[i + 1];
			ps->stack_a[i + 1] = tmp_num;
		}
		if (ps->num_el_in_stack_b > 1)
		{
			i = 0;
			tmp_num = ps->stack_b[i];
			ps->stack_b[i] = ps->stack_b[i + 1];
			ps->stack_b[i + 1] = tmp_num;
			write(1, &"sb\n", 3);
		}
		write(1, &"ss\n", 3);
	}
}

//pa (push a): Take the first element at the top of b and put
// it at the top of a.
//Do nothing if b is empty.
void	pa(t_push_swap *ps)
{
	int	i;

	if (ps->num_el_in_stack_b != 0)
	{
		i = ps->num_el_in_stack_a + 1;
		while (i > 0)
		{
			ps->stack_a[i] = ps->stack_a[i - 1];
			i--;
		}
		ps->num_el_in_stack_a++;
		ps->stack_a[0] = ps->stack_b[0];
		i = 0;
		while (i < ps->num_el_in_stack_b)
		{
			ps->stack_b[i] = ps->stack_b[i + 1];
			i++;
		}
		ps->num_el_in_stack_b--;
		write(1, &"pa\n", 3);
	}
}

//pb (push b): Take the first element at the top of
//a and put it at the top of b.
//Do nothing if a is empty.
void	pb(t_push_swap *ps)
{
	int	i;

	if (ps->num_el_in_stack_a != 0)
	{
		i = ps->num_el_in_stack_b + 1;
		while (i > 0)
		{
			ps->stack_b[i] = ps->stack_b[i - 1];
			i--;
		}
		ps->num_el_in_stack_b++;
		ps->stack_b[0] = ps->stack_a[0];
		i = 0;
		while (i < ps->num_el_in_stack_a)
		{
			ps->stack_a[i] = ps->stack_a[i + 1];
			i++;
		}
		ps->num_el_in_stack_a--;
		write(1, &"pb\n", 3);
	}
}
