/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <stopcic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:26:40 by stopcic           #+#    #+#             */
/*   Updated: 2023/04/18 08:45:50 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_cond = 1;

void	handle_signal(int signum, siginfo_t *siginfo, void *context)
{
	static unsigned char	ch;
	static int				bit = -1;
	pid_t					client_pid;

	client_pid = 0;
	(void)context;
	if (g_cond)
	{
		write(1, &"Connection is established...\n", 29);
		g_cond = 0;
	}
	if (!client_pid)
		client_pid = siginfo->si_pid;
	if (bit < 0)
		bit = 7;
	if (signum == SIGUSR1)
		ch |= (1 << bit);
	bit--;
	if (bit < 0 && ch)
	{
		write(1, &ch, 1);
		ch = 0;
	}
	kill(client_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sig_act;
	int					pid;

	pid = getpid();
	write(1, "PID is: ", 8);
	ft_putnbr(pid);
	sig_act.sa_sigaction = &handle_signal;
	sigemptyset(&sig_act.sa_mask);
	sig_act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sig_act, NULL) < 0)
	{
		write(1, "Error setting up signal handler for SIGUSR1\n", 44);
		return (1);
	}
	sigaction(SIGUSR2, &sig_act, NULL);
	sigaction(SIGUSR1, &sig_act, NULL);
	write(1, "\nWaiting for SIGUSR1 signal...\n", 31);
	while (1)
		usleep(500);
	return (0);
}
