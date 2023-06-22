/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:58:07 by stopcic           #+#    #+#             */
/*   Updated: 2022/11/07 19:57:03 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//#include <stdio.h>
#include <stdarg.h>

static int	print_para(const char *format, va_list args, int i);
static void	ft_putnbr_u(unsigned long long n);
static int	ft_nbcount(unsigned long long n);

static int	vprintk(const char *format, va_list args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{	
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			if (format[i] == 'c' || format[i] == 'd' || format[i] == 'i'
				|| format[i] == 'u' || format[i] == 'x' || format[i] == 'X'
				|| format[i] == 'p' || format[i] == 's' || format[i] == '%')
			{
				count += print_para(format, args, i);
				i++;
			}
		}
		else if (format[i] != '%')
		{
			count += ft_putchar_pf(format[i]);
			i++;
		}
	}
	return (count);
}

static int	print_para(const char *format, va_list args, int i)
{
	int		count;

	count = 0;
	if (format[i] == '%')
		count += ft_putchar_pf('%');
	else if (format[i] == 'c')
		count += ft_putchar_pf(va_arg(args, int));
	else if (format[i] == 's')
		count += ft_putstr_pf(va_arg(args, char *));
	else if ((format[i] == 'd' || format[i] == 'i')
		|| format[i] == 'X' || format[i] == 'x' || format[i] == 'p')
	{
		if (format[i] == 'd' || format[i] == 'i')
			count += ft_itoa_pf((unsigned int)va_arg(args, int));
		else if (format[i] == 'X' || format[i] == 'x')
			count += ft_int_hex((unsigned int)va_arg(args, int), format[i]);
		else if (format[i] == 'p')
			count += ft_int_ptr(va_arg(args, void *));
	}
	else if (format[i] == 'u')
		count += ft_nbcount(va_arg(args, unsigned int));
	i++;
	return (count);
}

static void	ft_putnbr_u(unsigned long long n)
{
	if (n < 10)
		ft_putchar_pf(n + '0');
	else
	{
		ft_putnbr_u((n / 10));
		ft_putnbr_u((n % 10));
	}
}

static int	ft_nbcount(unsigned long long n)
{
	int	count;

	count = 0;
	ft_putnbr_u(n);
	if (n == 0)
		count++;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;

	counter = 0;
	va_start(args, format);
	counter = vprintk(format, args);
	va_end(args);
	return (counter);
}
/*
int	main(void)
{
//	char	*pointer_main;
	int i;
	int j;
	i = 0;
	j = 0;
//	pointer_main = "koliko";
	i = ft_printf("print a characher: %c. Done! |%c|\n", 'H', 'O');
	printf("\n ft_printf c |%d|\n", i);
	j = printf("print a characher: %c. Done! |%c|\n", 'H', 'O');
	printf("\n ft_printf c |%d|\n", j);
	ft_printf("print a string: %s. Done!\n", "Hello world");
//	ft_printf("print a integer d: %d. Done!\n", 100);
//	ft_printf("print a neg integer d: %d. Done!\n", -100);
//	ft_printf("print a zero integer d: %d. Done!\n", 0);
//	ft_printf("print a integer i: %i. Done!\n", 100);
//	ft_printf("print a integer u: %u. Done!\n", -1000);
//	ft_printf("print a hexadecimal: %X. Done!\n", -100);
//	ft_printf("print a hexadecimal: %x. Done!\n", -100);
//	ft_printf("print a zero hexadecimalr: %x. Done!\n", 0);
//	ft_printf("print a pointer address: %p. Done!\n", &pointer_main);
//	ft_printf("print a characher: %%. Done!\n", '%');
	return (0);
}*/
