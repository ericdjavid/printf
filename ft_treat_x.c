/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 10:36:11 by edjavid           #+#    #+#             */
/*   Updated: 2021/04/24 11:40:03 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	treat_minus_x(the_flags *flags, int nb, unsigned long long x, int is_maj)
{
	int	count;
	int	i;

	i = flags[nb].precision;
	count = 0;
	if (flags[nb].minus == 1)
		print_hex_x(x, is_maj);
	count += ft_treat_width(flags, flags[nb].zero, nb, i);
	if (!flags[nb].minus)
	{
		if (flags[nb].precision > count_x(x))
		{
			i = flags[nb].precision;
			while (i > count_x(x))
			{
				ft_putchar_fd('0', 1);
				count++;
				i--;
			}
		}
		print_hex_x(x, is_maj);
	}
	return (count);
}

int	print_hex_x(unsigned long long n, int is_maj)
{
	if (n > 15)
		print_hex_x(n / 16, is_maj);
	if (is_maj)
		ft_putchar_fd(n % 16 > 9 ? n % 16 + 'A' - 10 : n % 16 + 48, 1);
	else
		ft_putchar_fd(n % 16 > 9 ? n % 16 + 'a' - 10 : n % 16 + 48, 1);
	return (1);
}

int	count_x(unsigned long long n)
{
	int length;

	length = 1;
	while (n > 15)
	{
		n /= 16;
		length++;
	}
	return (length);
}

int	ft_treat_x(va_list print_list, the_flags *flags, int nb, int is_maj)
{
	unsigned long long	x;
	int					count;
	int					i;

	x = va_arg(print_list, unsigned long long int);
	count = count_x(x);
	if (flags[nb].precision > count_x(x))
	{
		i = flags[nb].precision;
		while (i > count_x(x) && flags[nb].minus)
		{
			ft_putchar_fd('0', 1);
			count++;
			i--;
		}
	}
	count += treat_minus_x(flags, nb, x, is_maj);
	return (count);
}
