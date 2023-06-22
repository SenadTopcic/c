/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <stopcic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:13:43 by stopcic           #+#    #+#             */
/*   Updated: 2023/04/06 15:52:05 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAXNUM 2147483647
# define MINNUM -2147483648

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_push_swap
{
	int			*stack_a;
	int			*stack_b;
	int			num_el_in_stack_a;
	int			num_el_in_stack_b;
	int			max_size;
	int			new_arr_size;
	long int	*new_arr;
	long int	*index_arr;

	long int	*index_b;
	int			size_index_a;
	int			size_index_b;
}				t_push_swap;

int				ft_is_a_number_duplicated(int *stack_arr, char **user_input,
					int size);
void			make_me_free(int counter, char **stack_char, char *tmp_str,
					t_push_swap *ps);
int				check_me(char **stack_char, int counter);
char			*make_me_string(char **arr, int size, int counter);
int				ft_is_a_number_in_range(char *user_input);
int				give_me_size(char **arr, int counter);
int				ft_is_a_number(char *user_input);
char			**ft_split(char const *s, char c);
long long		ft_atoll(const char *str);
int				ft_strlen(const char *s);
int				two_d_arr_len(char **arr);

void			make_alg(t_push_swap *ps);
void			sa(t_push_swap *ps);
void			sb(t_push_swap *ps);
void			ss(t_push_swap *ps);

void			pa(t_push_swap *ps);
void			pb(t_push_swap *ps);
void			ra(t_push_swap *ps);
void			rb(t_push_swap *ps);
void			rr(t_push_swap *ps);
void			rra(t_push_swap *ps);
void			rrb(t_push_swap *ps);
void			rrr(t_push_swap *ps);

int				check_is_sorted(t_push_swap *ps);
void			hard_code_me_3(t_push_swap *ps);
void			make_index(t_push_swap *ps);
int				is_smallest_number(t_push_swap *ps, int position);

void			hard_code_me_4(t_push_swap *ps);
void			fix_3(t_push_swap *ps);
void			hard_code_me_5(t_push_swap *ps);
void			fix_5(t_push_swap *ps);
void			radix_sort(t_push_swap *ps);

void			pb_i(t_push_swap *ps);
void			ra_i(t_push_swap *ps);
void			pa_i(t_push_swap *ps);
void			rb_i(t_push_swap *ps);
int				check_is_sorted_index(t_push_swap *ps);
void			do_moves_in_radix(int size, int bit_size, t_push_swap *ps);

#endif
