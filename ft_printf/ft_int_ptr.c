/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:50:03 by stopcic           #+#    #+#             */
/*   Updated: 2022/11/07 19:55:45 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int_ptr(void *ptr)
{
	unsigned long long int		ptr_addr;
	int							counter;

	ptr_addr = (unsigned long long int)ptr;
	if (ptr_addr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	counter = ft_putstr_pf("0x");
	counter += ft_int_hex(ptr_addr, 'x');
	return (counter);
}
/*
int main(void)
{
	char *res = "2154516";
	//char *ptr = "KOLIKO";
	//printf("%s\n", ptr);
	printf("|%s|\n", ft_int_ptr(res));
	printf("100 %d\n", 200.20);
	return 0;
}*/
