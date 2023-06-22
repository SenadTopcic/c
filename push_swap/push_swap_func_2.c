/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_func_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <stopcic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:40:13 by stopcic           #+#    #+#             */
/*   Updated: 2023/04/07 09:53:54 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_me(char **stack_char, int counter)
{
	int	i;

	i = 0;
	while (i < counter)
	{
		if (!ft_is_a_number(stack_char[i])
			|| !ft_is_a_number_in_range(stack_char[i]))
			return (1);
		i++;
	}
	return (0);
}

void	make_me_free(int counter, char **stack_char,
	char *tmp_str, t_push_swap *ps)
{
	counter = 0;
	free(tmp_str);
	while (stack_char[counter] != NULL )
	{
		free(stack_char[counter]);
		counter++;
	}
	free(stack_char);
	free(ps->stack_a);
	free(ps->stack_b);
	free(ps->new_arr);
	free(ps->index_b);
	free(ps->index_arr);
	free(ps);
}
