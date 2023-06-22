/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:57:28 by stopcic           #+#    #+#             */
/*   Updated: 2022/11/07 19:58:00 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>

int		ft_int_hex(unsigned long long int c, char hex);
int		ft_int_ptr(void *ptr);
int		ft_putchar_pf(char c);
int		ft_putstr_pf(char *s);
int		ft_itoa_pf(int n);
int		ft_printf(const char *format, ...);
#endif
