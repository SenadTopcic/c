/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <stopcic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 12:34:08 by stopcic           #+#    #+#             */
/*   Updated: 2023/04/07 10:26:25 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_push_swap *ps, int counter)
{
	ps->stack_a = malloc(sizeof(int) * (counter + 1));
	ps->stack_b = malloc(sizeof(int) * (counter + 1));
	ps->new_arr = malloc(sizeof(long int) * (counter + 1));
	ps->index_arr = malloc(sizeof(long int) * (counter + 1));
	ps->num_el_in_stack_a = counter;
	ps->num_el_in_stack_b = 0;
	ps->max_size = counter;
	ps->new_arr_size = counter;
	ps->index_b = malloc(sizeof(long int) * (counter + 1));
	ps->size_index_a = counter;
	ps->size_index_b = 0;
}

int	main(int ac, char **argv)
{
	t_push_swap	*ps;
	int			counter;
	char		**stack_char;
	char		*tmp_str;

	if (ac >= 2)
	{
		ps = malloc(sizeof(t_push_swap) + 1);
		counter = ac - 1;
		tmp_str = make_me_string(argv, give_me_size(argv, counter), counter);
		stack_char = ft_split(tmp_str, ' ');
		counter = two_d_arr_len(stack_char);
		init(ps, counter);
		if (ft_is_a_number_duplicated(ps->stack_a, stack_char, counter)
			|| check_me(stack_char, counter))
		{
			make_me_free(counter, stack_char, tmp_str, ps);
			return (1);
		}
		make_index(ps);
		make_alg(ps);
		make_me_free(counter, stack_char, tmp_str, ps);
	}
	return (1);
}
