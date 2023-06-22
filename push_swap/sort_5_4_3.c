/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_4_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <stopcic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:42:22 by stopcic           #+#    #+#             */
/*   Updated: 2023/04/04 17:32:52 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//function sort 3 elements in array
void	hard_code_me_3(t_push_swap *ps)
{
	if (ps->stack_a[0] > ps->stack_a[1] && ps->stack_a[0] > ps->stack_a[2])
	{
		ra(ps);
		if (!check_is_sorted(ps))
			sa(ps);
	}
	else if (ps->stack_a[0] > ps->stack_a[1]
		&& (ps->stack_a[0] < ps->stack_a[2]))
		sa(ps);
	else if ((ps->stack_a[0] < ps->stack_a[1]
			&& ps->stack_a[0] > ps->stack_a[2]))
		rra(ps);
	else if (ps->stack_a[0] < ps->stack_a[1] && ps->stack_a[0] < ps->stack_a[2])
	{
		sa(ps);
		ra(ps);
	}
}

//function sort 4 elements in array
void	hard_code_me_4(t_push_swap *ps)
{
	if (is_smallest_number(ps, 0))
		fix_3(ps);
	else if (is_smallest_number(ps, 1))
	{
		sa(ps);
		fix_3(ps);
	}
	else if (is_smallest_number(ps, 2))
	{
		rra(ps);
		rra(ps);
		fix_3(ps);
	}
	else
	{
		rra(ps);
		fix_3(ps);
	}
}

//function sort_fix 3 arguments
void	fix_3(t_push_swap *ps)
{
	if (!check_is_sorted(ps))
	{
		pb(ps);
		hard_code_me_3(ps);
		pa(ps);
	}
}

//function sort 5 elements in array
void	hard_code_me_5(t_push_swap *ps)
{
	if (is_smallest_number(ps, 0))
		fix_5(ps);
	else if (is_smallest_number(ps, 1))
	{
		sa(ps);
		fix_5(ps);
	}
	else if (is_smallest_number(ps, 2))
	{
		ra(ps);
		ra(ps);
		fix_5(ps);
	}
	else if (is_smallest_number(ps, 3))
	{
		rra(ps);
		rra(ps);
		fix_5(ps);
	}
	else
	{
		rra(ps);
		fix_5(ps);
	}
}

void	fix_5(t_push_swap *ps)
{
	pb(ps);
	hard_code_me_4(ps);
	pa(ps);
}
