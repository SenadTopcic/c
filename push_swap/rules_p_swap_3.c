/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_p_swap_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <stopcic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:44:47 by stopcic           #+#    #+#             */
/*   Updated: 2023/04/03 18:44:30 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 rrr : rra and rrb at the same time.
 */
void	rrr(t_push_swap *ps)
{
	int	i;
	int	tmp_int_a;
	int	tmp_int_b;

	i = ps->max_size - 1;
	tmp_int_a = ps->stack_a[ps->max_size - 1];
	tmp_int_b = ps->stack_b[ps->max_size - 1];
	while (i > 0)
	{
		ps->stack_a[i] = ps->stack_a[i - 1];
		ps->stack_b[i] = ps->stack_b[i - 1];
		i--;
	}
	ps->stack_a[0] = tmp_int_a;
	ps->stack_b[0] = tmp_int_b;
	write(1, &"rrr\n", 3);
}
