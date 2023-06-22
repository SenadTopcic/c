/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:01:02 by stopcic           #+#    #+#             */
/*   Updated: 2022/11/08 11:01:42 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

int	ft_putstr_pf(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		j += ft_putchar_pf(s[i]);
		i++;
	}
	return (j);
}
/*
int main()
{
	printf(" NULL %s NULL ", NULL);
	ft_putstr_pf("kako je");
	return (0);

}*/
