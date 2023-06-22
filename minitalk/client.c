/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <stopcic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:26:53 by stopcic           #+#    #+#             */
/*   Updated: 2023/04/01 20:39:26 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_received = 0;

void	handler_client(int signum)
{
	if (signum == SIGUSR2)
	{
		g_received++;
	}
}

void	send_char_to_server(int pid, char c)
{
	int	bit;
	int	a;

	bit = 7;
	while (bit >= 0)
	{
		a = g_received;
		if (c >> bit & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (a == g_received)
		{
		}
		bit--;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	if (ac != 3)
	{
		write(1, &"Please enter the server PID and the string\n", 42);
		return (1);
	}
	pid = ft_atoi(av[1]);
	signal(SIGUSR1, &handler_client);
	signal(SIGUSR2, &handler_client);
	while (av[2][i])
	{
		send_char_to_server(pid, av[2][i]);
		i++;
	}
	send_char_to_server(pid, '\n');
	return (0);
}
