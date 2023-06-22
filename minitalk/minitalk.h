/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <stopcic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:13:43 by stopcic           #+#    #+#             */
/*   Updated: 2023/04/01 20:39:57 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void	send_char_to_server(int pid, char c);
void	handle_signal(int signum, siginfo_t *siginfo, void *context);
void	handler_client(int signum);
int		ft_atoi(const char *str);
void	ft_putnbr(int n);
void	ft_putchar(char ch);

#endif
